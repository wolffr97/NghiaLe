<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    
    <title>Danh sách checkout</title>
    <style>
      body{
        font-family: DejaVu Sans, sans-serif, font-size: 10px;
      }
      table {
          border-collapse: collapse;
      }

      table, td, th {
          padding-left: 4px;
          padding-right: 4px;
          border: 1px solid black;
      }
    </style>
  </head>
  
  <body >
    <div style="text-align: right">
      <p>Ngày In: <?php echo date("d-m-Y") ?></p>
    </div>
    <hr>
    <center><h2>DANH SÁCH CHECKOUT</h2></center>
    <br>
       <table>
      <thead>
        <tr>
          <td width="5%"><strong>STT</strong></td>
          <td width="10%"><strong>Tên phòng</strong></td>
          <td width="10%"><strong>Loại thuê</strong></td>
          <td width="15%"><strong>Đơn giá</strong></td>
          <td width="10%"><strong>Thời gian vào</strong></td>
          <td width="10%"><strong>Thời gian ra</strong></td>
          <td width="10%"><strong>Thời gian đã thuê</strong></td>
          <td width="15%"><strong>Phụ thu</strong></td>
          <td><strong>Tổng giá</strong></td>
        </tr>
      </thead>
      <tbody>
        <?php $count = 0; ?>
            @foreach ($data as $item)
            <tr >
              <td >{!! $count = $count + 1 !!}</td>
              <td >{!! $item['roomName'] !!}</td>
              <td >{!! $item['rent_type'] !!}</td>
              <td >{!! number_format($item['cost']) !!} VND</td>
              <td >{!! $item['time_in'] !!}</td>
              <td >{!! $item['time_out'] !!}</td>
              <td >{!! $item['rent_num'] !!}</td>
              <td >{!! number_format($item['extraCost']) !!} VND</td>
              <td >{!! number_format($item['allCost']) !!} VND</td>
          </tr>
            @endforeach
            
      </tbody>
    </table>
    <h3>Thống kê doanh thu: </h3>
    <table>
      <tr>
        <td>Số lượng checkout</td>
        <td>{!! count($data) !!}</td>
      </tr>
      <tr>
        <td>Tổng doanh thu phòng</td>
        <td>{!! number_format($revenue_room) !!} VND</td>
      </tr>
      <tr>
        <td>Tổng phụ thu</td>
        <td>{!! number_format($revenue_extra) !!} VND</td>
      </tr>
      <tr>
        <td>Tổng cộng</td>
        <td>{!! number_format($revenue_all) !!} VND</td>
      </tr>
    </table> 
  </body>
</html>
    
