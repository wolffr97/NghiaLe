app.controller('HotelRoomController', function ($scope, $http, $location, API){
    $http({
        method: 'GET',
        url: API + 'hotel/room/list'
    }).then(function (success){
        $scope.rooms = success.data;
    },function (error){

    });

    $scope.modal = function (state,id) {
           $scope.state = state;
           console.log(state);
        switch (state) {
            case "add" :
                $scope.roomTitle = "Thêm phòng mới";
                $http.get(API + 'hotel/price/list').success(function (response) {
                    //$scope.prices = response;
                    console.log(response);
                    $scope.prices = {
                        model: null,
                        availableOptions: response
                       };
                });
                break;
            case "edit" :
                $scope.roomTitle = "Sửa Phòng";
                $scope.id = id;
                $http.get(API + 'hotel/room/edit/' + id).success(function (response) {
                    $scope.hotelroom = response;
                });
                break;
            default :
                $scope.roomTitle = "Không tồn tại";
                break;
        }
        //.location.href = 'room/add';
        $("#myModal").modal('show');

    }

    $scope.save = function (state,id){
           if (state == "add") {
            var url = API + 'hotel/room/add';
            var data = $.param($scope.hotelroom);
            $http({
                method : 'POST',
                url : url,
                data : data,
                headers : {'Content-Type':'application/x-www-form-urlencoded'}
            })
            .success(function (response) {
                location.reload();
            })
            .error(function (response) {
                alert('Xảy ra lỗi vui lòng kiểm tra log');
            });
        }

        if (state == "edit") {
            var url = API + 'hotel/room/edit/' + id;
            var data = $.param($scope.hotelroom);
            $http({
                method : 'POST',
                url : url,
                data : data,
                headers : {'Content-Type':'application/x-www-form-urlencoded'}
            })
            .success(function (response) {
                location.reload();
            })
            .error(function (response) {
                alert('Xảy ra lỗi vui lòng kiểm tra log');
            });
        }
    }
    $scope.confirmDelete = function (id) {
        var isConfirmDelete = confirm('Bạn có chắc muốn xóa dòng dữ liệu này hay không');
        if (isConfirmDelete) {
            $http.get(API + 'hotel/room/delete/' + id)
                .success(function (response) {
                    location.reload();
                })
                .error(function(response) {
                    alert('Xảy ra lỗi vui lòng kiểm tra log');
                });;
        } else {
            return false;
        }
    }
});
