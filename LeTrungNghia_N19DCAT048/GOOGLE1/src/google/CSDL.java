package google;


import java.sql.*;
import javax.swing.JComboBox;
import javax.swing.table.DefaultTableModel;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author lengh
 */
public class CSDL {
    private Connection connection;
    

    public CSDL() {
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            connection = DriverManager.getConnection("jdbc:sqlserver://;databaseName=GOOGLE","sa","123");
            System.out.println("Connet succeesed");
        } catch (Exception e) {
            System.out.println("Connect error" + e);
        }
    }

 



    
    public String TimTenNgDung(String tenNgDung){
        String query = String.format("select * from NGUOIDUNG where TENND = '%s'", tenNgDung);
        
        try{
            ResultSet data = connection.prepareStatement(query).executeQuery();
            if(data.next()){
                return data.getString("TENND");
            }
        }catch(Exception e){
            System.out.println("Error: " + e);
        }
        
        return "Khong Co Nguoi Dung";
    }
    public void ThemTaiKhoan(String hoTen, String tenNgDung, String matKhau, String sdt,String email,String ngaySinh,String gioiTinh){
        
        
        String query = String.format("insert into NGUOIDUNG values(N'%s','%s','%s','%s','%s','%s',N'%s')",hoTen , tenNgDung , matKhau, sdt,email,ngaySinh,gioiTinh );
        
        try{
            connection.prepareStatement(query).executeUpdate();
        }catch(Exception e){
            System.out.println("error" + e);
        }
        
    }
    
    public static void main(String[] args) {
        CSDL csdl = new CSDL();
        
       // System.out.println(csdl.TimTenNgDung("lenghia97@gmail.com"));
        csdl.ThemTaiKhoan("Le Loan", "cay@gmail.com", "propro", "0123456709", "", "1997-02-09", "Nam");
    }
}
