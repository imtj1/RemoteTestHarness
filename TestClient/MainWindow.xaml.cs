/*
* Package Operations:
* -------------------
* This package contains the implementation for GUI of the application, it takes care of all the realted logic in the UI
* @author : Tony Joseph
* Language:    Visual C#, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* using System.Windows;
* using System.Windows.Input;
* using System.IO;
* using MsgPassingCommunication;
* using System.Threading;
* using System;
* using System.Collections.Generic;
* using System.Text.RegularExpressions;
* using System.Windows.Controls;
* using System.ComponentModel;
*/
using System.Windows;
using System.Windows.Input;
using System.IO;
using MsgPassingCommunication;
using System.Threading;
using System;
using System.Collections.Generic;
using System.Windows.Controls;
using System.ComponentModel;

namespace TestClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public string Path { get; set; }
        int Port = 0;
        private Thread rcvThrd = null;
        private Boolean demo = false;
        private int testRequestNumber = 0;
        private Dictionary<string, Action<CsMessage>> dispatcher_ = new Dictionary<string, Action<CsMessage>>();
        private int demoResultFileNumber = 0;
        public MainWindow()
        {
            InitializeComponent();
        }

        private Translater translater;
        private CsEndPoint endPoint_;
        
        //----< initial logic when window loads up >------
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            string[] args = Environment.GetCommandLineArgs();
            Port = int.Parse(args[2]);
            portNumber.Content = Port.ToString();
            demo = args[1].Equals("demo");
            DispatcherLoadGetDirs();
            Path = System.IO.Path.GetFullPath(@"..\..\..\TestLibraries");
            LoadNavTab(Path);
            translater = new Translater();
            endPoint_ = new CsEndPoint
            {
                machineAddress = "localhost",
                port = Port
            };

            translater.listen(endPoint_);
            ProcessMessages();

            CsEndPoint TestHarnessProcessPool = new CsEndPoint
            {
                machineAddress = "localhost",
                port = 8081
            };

            CsMessage msg = new CsMessage();
            msg.add("to", CsEndPoint.toString(TestHarnessProcessPool));
            msg.add("from", CsEndPoint.toString(endPoint_));
            msg.add("sendFilePath", "../../../TestLibraries/");
            msg.add("saveFilePath", "../../../TestResults@Client"+ Port+"/");
            msg.add("setPaths", "");
            msg.add("Register", "");
            translater.postMessage(msg);
            if (demo)
            {
                Test();
            }
        }
        //----< logic when window shuts down >------
        void Window_Closing(object sender, CancelEventArgs e)
        {
            CsEndPoint TestHarnessProcessPool = new CsEndPoint
            {
                machineAddress = "localhost",
                port = 8081
            };
            CsMessage msg = new CsMessage();
            msg.add("to", CsEndPoint.toString(TestHarnessProcessPool));
            msg.add("from", CsEndPoint.toString(endPoint_));
            msg.add("ClientDone", "");
            translater.postMessage(msg);
        }
        //----< initial logic when window closes >------
        void Window_Closed(object sender, EventArgs e)
        {
            CsMessage stopMessage = new CsMessage();
            stopMessage.add("stop", "");
            translater.postMessage(stopMessage);
        }
        //----< process messages for receiving messges from child processes >------
        private void ProcessMessages()
        {
            void thrdProc()
            {
                while (true)
                {
                    CsMessage msg = translater.getMessage();
                    if (msg.attributes.ContainsKey("sendingFile"))
                    {
                        if (dispatcher_.ContainsKey("getDirs"))
                            dispatcher_["getDirs"].Invoke(msg);
                    }
                }
            }
            rcvThrd = new Thread(thrdProc)
            {
                IsBackground = true
            };
            rcvThrd.Start();
        }
        //----< client proc for adding the function into a map >------
        private void AddClientProc(string key, Action<CsMessage> clientProc)
        {
            dispatcher_[key] = clientProc;
        }
        //----< dispatching UI change into main function >------
        private void DispatcherLoadGetDirs()
        {
            Action<CsMessage> getDirs = (CsMessage rcvMsg) =>
            {
                Action<string> clrDirs = (string a) =>
                {
                    AddResult(a);
                };
                Dispatcher.Invoke(clrDirs, new Object[] { rcvMsg.value("sendingFile") });
            };
            AddClientProc("getDirs", getDirs);
        }
        //----< adding the result files into result box >------
        void AddResult(string dir)
        {
            ResultBox.Items.Add(dir);
            if (demo)
            {
                ResultBox.SelectedItem = ResultBox.Items[demoResultFileNumber++];
                Results_Files_Double_Click(new object(), null);
            }
            else
            {
                MessageBox.Show("Results are available in Test Results tab under file name " + dir, "Results Received", MessageBoxButton.OK, MessageBoxImage.Information);
            }
        }
        //----< loading files from the directory >------
        void LoadNavTab(string path)
        {
            CurrentPath.Text = path;
            Files.Items.Clear();
            string[] files = Directory.GetFiles(path);
            foreach (string file in files)
            {
                string name = System.IO.Path.GetFileName(file);
                Files.Items.Add(name);
            }
        }
        //----< opening file from results >------
        private void Results_Files_Double_Click(object sender, MouseButtonEventArgs e)
        {
            string FileName = ResultBox.SelectedItem.ToString();
            string path = System.IO.Path.Combine(Directory.GetCurrentDirectory(), @"..\..\..\TestResults@Client" + Port + "\\" + FileName);
            string result = File.ReadAllText(path);
            PopupWindow popup = new PopupWindow
            {
                WindowState = WindowState.Maximized
            };
            popup.Title = path;
            popup.TextContent.Text = result;
            popup.Show();
        }
        //----< adding files to selected files >------
        private void Files_Double_Click(object sender, MouseButtonEventArgs e)
        {
            demo = false;
            if (e.OriginalSource is TextBlock)
            {
                string selectedFile = Files.SelectedItem.ToString();
                if (System.IO.Path.GetExtension(selectedFile) == ".dll")
                {
                    SelectedFiles.Items.Add(selectedFile);
                    List<object> list = new List<object>();
                    foreach (object o in SelectedFiles.Items)
                    {
                        if (!list.Contains(o))
                        {
                            list.Add(o);
                        }
                    }
                    SelectedFiles.Items.Clear();
                    foreach (object o in list)
                    {
                        SelectedFiles.Items.Add(o);
                    }
                }
                else
                {
                    MessageBox.Show("Only Dll's are allowed", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
        }
        //----< remove file from selected files >------
        private void Selected_Files_Double_Click(object sender, MouseButtonEventArgs e)
        {
            SelectedFiles.Items.RemoveAt(SelectedFiles.Items.IndexOf(SelectedFiles.SelectedItem));
        }
        //----< remove all file from selected files >------
        private void Clear_Selected_Items(object sender, RoutedEventArgs e)
        {
            SelectedFiles.Items.Clear();
        }
        //----< execute test libraries in the selected files >------
        private void Execute_Tests(object sender, RoutedEventArgs e)
        {
            if (SelectedFiles.Items.Count == 0)
                return;
            CsEndPoint TestHarnessProcessPool = new CsEndPoint
            {
                machineAddress = "localhost",
                port = 8081
            };
            CsMessage testReq = new CsMessage();
            testReq.add("to", CsEndPoint.toString(TestHarnessProcessPool));
            testReq.add("from", CsEndPoint.toString(endPoint_));
            string TestRequestName = "TestRequest_" + (++testRequestNumber) +"_"+ Port;
            string TestRequest = TestRequestName + ",TonyJoseph,";
            foreach (object o in SelectedFiles.Items)
            {
                SendFileToHost(o.ToString(), TestHarnessProcessPool);
                TestRequest += "," + o.ToString();
            }

            testReq.add("TestRequest", TestRequest);
            translater.postMessage(testReq);
            Clear_Selected_Items(null, null);
            if (!demo)
            {
                MessageBox.Show("Test Request: " + TestRequestName + " send for testing", "Sent", MessageBoxButton.OK, MessageBoxImage.Information);
            }
        }
        //----< send files to host >------
        private void SendFileToHost(string fileName, CsEndPoint endPoint)
        {
            CsMessage sendFileMsg = new CsMessage();
            sendFileMsg.add("to", CsEndPoint.toString(endPoint));
            sendFileMsg.add("from", CsEndPoint.toString(endPoint_));
            sendFileMsg.add("sendingFile", fileName);
            translater.postMessage(sendFileMsg);
        }
        //----< automated test on startup  >------
        private void Test()
        {
            if (Port == 8080)
            {
                SelectedFiles.Items.Add("DemoRequirements.dll");
                Execute_Tests(new object(), new RoutedEventArgs());
            }
            else
            {
                SelectedFiles.Items.Add("TestDlll1.dll");
                Execute_Tests(new object(), new RoutedEventArgs());
                SelectedFiles.Items.Add("TestDlll2.dll");
                Execute_Tests(new object(), new RoutedEventArgs());
            }
        }
    }
}
