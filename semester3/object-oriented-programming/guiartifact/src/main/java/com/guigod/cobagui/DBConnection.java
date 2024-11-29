package com.guigod.cobagui;

import java.sql.*;
import java.util.Map;

public class DBConnection {
    static Connection connection;
    public static Connection getConnection() {
        try {
            String url = "jdbc:mariadb://localhost/pbo_latihanperpus";
            Map<String, String> env_variables = System.getenv();
            String user = env_variables.get("DB_USER");
            String password = env_variables.get("DB_PASSWORD");
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException err) {
            System.out.println("Error Connecting to Database");
            System.out.println(err.getMessage());
        }
        return connection;
    }
    }
