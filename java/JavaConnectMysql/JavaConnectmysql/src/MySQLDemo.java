//package connect;

import java.sql.*;
public class connectDB {
 
    // MySQL 8.0 以上版本 - JDBC 驱动名及数据库 URL
    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://localhost:3306/mysql?useSSL=false&serverTimezone=UTC";
 
    // 数据库的用户名与密码，需要根据自己的设置
    static final String USER = "root";
    static final String PASS = "SteinsGate001";
    public static void main(final String[] args) {
        Connection conn = null;
        Statement stmt = null;
        try {
            // 注册 JDBC 驱动
            Class.forName(JDBC_DRIVER);

            // 打开链接
            System.out.println("连接数据库...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);

            // 执行查询
            System.out.println(" 实例化Statement对象...");
            stmt = conn.createStatement();
            String sql;
            sql = "select * from employee  where user_name like \"王%\";";
            final ResultSet rs = stmt.executeQuery(sql);

            // 展开结果集数据库
            while (rs.next()) {
                // 通过字段检索
                final String user_id = rs.getString("user_id");
                final String user_name = rs.getString("user_name");
                final String telephone = rs.getString("telephone");
                final String mail = rs.getString("mail");
                final String user_status = rs.getString("user_status");

                // 输出数据
                System.out.print("user_id: " + user_id);
                System.out.print(", user_name: " + user_name);
                System.out.print(", telephone: " + telephone);
                System.out.print(", mail: " + mail);
                System.out.print(", user_status: " + user_status);
                System.out.print("\n");
            }
            // 完成后关闭
            rs.close();
            stmt.close();
            conn.close();
        } catch (final SQLException se) {
            // 处理 JDBC 错误
            se.printStackTrace();
        } catch (final Exception e) {
            // 处理 Class.forName 错误
            e.printStackTrace();
        } finally {
            // 关闭资源
            try {
                if (stmt != null)
                    stmt.close();
            } catch (final SQLException se2) {
            } // 什么都不做
            try {
                if (conn != null)
                    conn.close();
            } catch (final SQLException se) {
                se.printStackTrace();
            }
        }
        System.out.println("Goodbye!");
    }
}