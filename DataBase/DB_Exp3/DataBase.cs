using System;
using System.Data;
using System.Data.SqlClient;

namespace DB_Exp3
{
    class DataBase
    {
        readonly string connectStr = "server=localhost;Trusted_Connection=true";
        private bool running = false;

        SqlConnection sqlConnection;

        public bool loginDB()
        {
            if (!running)
            {
                sqlConnection = new SqlConnection(connectStr);

                sqlConnection.Open();
                running = true;

                return true;
            }
            return false;
        }
        public DataSet DataSelect(string commandText)
        {
            if (!running)
            {
                return null;
            }

            DataSet ds = new DataSet();
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(commandText, sqlConnection);
            sqlDataAdapter.Fill(ds);

            return ds;
        }
        public string DataDelete(string commandText)
        {
            SqlCommand sqlCommand = new SqlCommand(commandText, sqlConnection);
            int str = sqlCommand.ExecuteNonQuery();

            return str.ToString();
        }
        public string DataUpdate(string commandText)
        {
            SqlCommand sqlCommand = new SqlCommand(commandText, sqlConnection);
            int str = sqlCommand.ExecuteNonQuery();

            return str.ToString();
        }
        public bool logoutDB()
        {
            if (running)
            {
                sqlConnection.Close();
                running = false;

                return true;
            }
            return false;
        }

    }
}
