using System.Threading;
using System.Windows;
using System.Windows.Controls;

namespace RNG.UserInterface
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow
    {

        private static EventWaitHandle _ewh;
        private static EventWaitHandle _customerEwh;
        private readonly object _vault = new object();
        private CustomerWrapper _customer;

        public MainWindow()
        {
            InitializeComponent();
            _ewh = new EventWaitHandle(false,EventResetMode.AutoReset);
            _customerEwh = new EventWaitHandle(false,EventResetMode.AutoReset);
        }

        private void btnGenerate_Click(object sender, RoutedEventArgs e)
        {
            IsEnabled_Generate(false);
            var t = new Thread(NumGenProc);
            t.Start();
        }

        private void UpdateListBox(string value)
        {
            var lbItem = new ListBoxItem() { Content = value };
            lbResults.Items.Add(lbItem);
        }

        private void UpdateStatus(string value)
        {
            txtResult.Text = value;
        }

        private void IsEnabled_Generate(bool value)
        {
            BtnGenerate.IsEnabled = value;
        }


        private void CallUi_UpdateNumberList(string args)
        {
            Dispatcher.Invoke(() => { UpdateListBox(args); });
            _ewh.WaitOne();
            //var temp = args;
        }

        private void CallUI_SetCustomerContext(CustomerWrapper customer)
        {
            lock (_vault)
            {
                _customer = customer;
            }
            Dispatcher.Invoke(SetDataContext);
            _customerEwh.WaitOne();
        }

        private void btnSignal_Click(object sender, RoutedEventArgs e)
        {
            _ewh.Set();
        }

        private void NumGenProc()
        {
            var rng = new RngWrapper();
            rng.sendbackEvent += CallUi_UpdateNumberList;
            var noArray = rng.RandomArray();

            Dispatcher.Invoke(() => { IsEnabled_Generate(true); });
            Dispatcher.Invoke(() => { UpdateStatus(noArray.Count.ToString()); });
        }

        private void SetDataContext()
        {
            lock (_vault)
            {
                txtFirstName.Text = _customer.FirstName;
                txtLastName.Text = _customer.LastName;
                txtCustomerId.Text = _customer.CustomerId.ToString();
            }
        }

        private void CustFetchProc()
        {
            var rng = new RngWrapper();
            rng.customerSendbackEvent += CallUI_SetCustomerContext;

            _customer = rng.CreateCustomer();

            Dispatcher.Invoke(
                () =>
                {
                    UpdateStatus($"Customer {_customer.FirstName} {_customer.LastName}, Id: {_customer.CustomerId}");
                });
        }

        private void btnCustomer_Click(object sender, RoutedEventArgs e)
        {
            var t = new Thread(CustFetchProc);
            t.Start();
        }

        private void btnSubmit_Click(object sender, RoutedEventArgs e)
        {
            lock (_vault)
            {
                _customer.FirstName = txtFirstName.Text;
                _customer.LastName = txtLastName.Text;
                int id;
                if (int.TryParse(txtCustomerId.Text, out id))
                {
                    _customer.CustomerId = id;
                }
            }
            _customerEwh.Set();
        }
    }
}
