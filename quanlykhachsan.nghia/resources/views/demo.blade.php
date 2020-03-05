<!DOCTYPE html>
<html lang="">
	<head>
		<meta charset="utf-8">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<title>Title Page</title>

		<!-- Bootstrap CSS -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">

		<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
		<![endif]-->
	</head>
	<body>

<!-- 		<div class="form-group">
		    <label>State</label>
		    <?php  $data = DB::table('nhaphanphoi')->get();
		    ?>
		        <select name="state" id="state" class="form-control input-sm">
		        @foreach($data as $item)
		            <option value="{{ $item->id}}">{{ $item->npp_ten}}</option>
		           
		         @endforeach
		        </select>
		    
		</div>
		 
		<div class="form-group">
		    <label>Address</label>
		       <input id="city" type="text" name="city_id" value="">
		</div> -->


		<div class="form-group">
        <label>Albums</label>
        <select class="form-control" name="state_id" id="state_id">
            @foreach($data as $item)
		            <option value="{{ $item->id}}">{{ $item->npp_ten}}</option>
		           
		         @endforeach
        </select>
    </div>

    <div class="form-group">
        <label>Diachi</label>
        <select class="form-control input-sm" name="diachi" id="city">
                <option value=""></option>
        </select>
    </div>

    <div class="form-group">
        <label>sdt</label>
        <select class="form-control input-sm" name="sdt" id="city1">
                <option value="">
                </option>
        </select>
    </div>

    <div class="form-group">
        <label>fax</label>
        <select class="form-control input-sm" name="fax" id="city2">
                <option value=""></option>
        </select>
    </div>

		<!-- jQuery -->
		<script src="//code.jquery.com/jquery.js"></script>
		<!-- Bootstrap JavaScript -->
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js" integrity="sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS" crossorigin="anonymous"></script>
		
		<script>
	        $('#state_id').on('change', function(e) {
	            console.log(e);
	            var state_id = e.target.value;

	            //ajax

	            $.getJSON("nhaphanphoi/ajax-call?state_id="+state_id, function (data) {

					console.log(data);

	                $('#city').empty();
	                $.each(data, function(index, cityObj){

	                     $('#city').append('<option value="'+cityObj.id+'">'+cityObj.npp_diachi+'</option>');
	                });

					$('#city1').empty();
	                $.each(data, function(index, sdtObj){

	                     $('#city1').append('<option value="'+sdtObj.id+'">'+sdtObj.npp_sdt+'</option>');
	                });

	                $('#city2').empty();
	                $.each(data, function(index, sdtObj){

	                     $('#city2').append('<option value="'+sdtObj.id+'">'+sdtObj.npp_fax+'</option>');
	                });
	            });

	        });
    </script>
	</body>
</html>