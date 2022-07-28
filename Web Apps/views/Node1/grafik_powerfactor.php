<script>
var refreshId = setInterval(function()
{
    $('#responsecontainer').load('./views/Node1/data_powerfactor.php');
}, 1000);
</script>

<script src="jquery-latest.js"></script>
<script type="text/javascript" src="aset/js/jquery-3.4.0.min.js"></script>
<script type="text/javascript" src="aset/js/mdb.min.js"></script>

<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title></title>
</head>
<body>
  <div class="container">
    <div class="center" id="responsecontainer" style="width: 75%"></div>
  </div>
</body>
</html>

