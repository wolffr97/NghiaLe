<div class="leftpanel">
    <div class="logopanel">
        <h1><span>[</span>KHÁCH SẠN<span>]</span></h1>
    </div><!-- logopanel -->
    
    <div class="leftpanelinner">
       
        <!-- This is only visible to small devices -->
        <div class="visible-xs hidden-sm hidden-md hidden-lg">
            <div class="media userlogged">
                <img alt="" src="{{url('/')}}/resources/assets/images/photos/loggeduser.png" class="media-object">
                <div class="media-body">
                    <h4>Hotel Management</h4>
                    <!--<span>"Life is so..."</span>-->
                </div>
            </div>
          
            <h5 class="sidebartitle actitle">Account</h5>
            <ul class="nav nav-pills nav-stacked nav-bracket mb30">
              <li><a href="login"><i class="fa fa-sign-out"></i> <span>Sign Out</span></a></li>
            </ul>
        </div>
      
        <ul class="nav nav-pills nav-stacked nav-bracket">
            <li id="room"><a href="{{url('/hotel/room')}}"><i class="fa fa-building"></i> <span>Quản lý phòng</span></a></li>
            <li id="price"><a href="{{url('/hotel/price')}}"><i class="fa fa-money"></i> <span>Quản lý giá phòng</span></a></li>
            <li id="so-do-phong"><a href="{{url('/hotel/so-do-phong')}}"><i class="fa fa-sitemap"></i> <span>Sơ đồ phòng</span></a></li>
            <li id="checkin"><a href="{{url('/hotel/checkin')}}"><i class="fa fa-sign-in"></i> <span>Quản lý Checkin</span></a></li>
            <li id="checkout"><a href="{{url('/hotel/checkout')}}"><i class="fa fa-sign-out"></i> <span>Quản lý Checkout</span></a></li>
        </ul>
      
        <!-- <div class="infosummary">
            <h5 class="sidebartitle">Information Summary</h5>
            <ul>
                <li>
                    <div class="datainfo">
                        <span class="text-muted">Daily Traffic</span>
                        <h4>630, 201</h4>
                    </div>
                    <div id="sidebar-chart" class="chart"></div>
                </li>
                <li>
                    <div class="datainfo">
                        <span class="text-muted">Memory Usage</span>
                        <h4>32.2%</h4>
                    </div>
                    <div id="sidebar-chart5" class="chart"></div>
                </li>
            </ul>
        </div> --><!-- infosummary -->
    </div><!-- leftpanelinner -->
</div><!-- leftpanel -->
