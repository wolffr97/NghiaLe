<?php
  function Select_Function($data, $select=0)
     {
         foreach ($data as  $val) {
              $id = $val['id'];
              $name = $val['name'];
              if ($select != 0 && $id == $select) {
                    echo "<option value='$id' selected = 'true'>$name</option>";
              } else {
                    echo "<option value='$id'>$name</option>";                            
         }
     }
    }
?>