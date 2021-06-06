using System;
using System.Data;
using System.Data.SqlClient;

namespace DB_Exp3
{
    internal class DataBase
    {
        private const string ConnectStr = "server=localhost;Trusted_Connection=true";
        private bool _running = false;

        private SqlConnection _sqlConnection;

        public DataBase()
        {
            _running = false;
        }

        public bool LoginDb()
        {
            if (_running) return false;
            
            _sqlConnection = new SqlConnection(ConnectStr);
            try
            {
                _sqlConnection.Open();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                return false;
            }

            _running = true;
            return true;
        }

        public DataSet DataSelect(string commandText)
        {
            if (!_running) return null;

            var ds = new DataSet();
            var sqlDataAdapter = new SqlDataAdapter(commandText, _sqlConnection);
            sqlDataAdapter.Fill(ds);

            return ds;
        }

        public string DataDelete(string commandText)
        {
            var sqlCommand = new SqlCommand(commandText, _sqlConnection);
            var str = sqlCommand.ExecuteNonQuery();

            return str.ToString();
        }

        public string DataUpdate(string commandText)
        {
            var sqlCommand = new SqlCommand(commandText, _sqlConnection);
            var str = sqlCommand.ExecuteNonQuery();

            return str.ToString();
        }

        public bool LogoutDb()
        {
            if (!_running) return false;
            
            _sqlConnection.Close();
            _running = false;

            return true;
        }
    }
}