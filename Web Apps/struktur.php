<?php
ob_start();
require_once('config/+koneksi.php');
require_once('models/database.php');

$connection = new Database($host, $user, $pass, $database);
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Monitoring Listrik</title>

    <!-- Bootstrap core CSS -->
    <link rel="stylesheet" href="aset/css/bootstrap.css">
    <link rel="stylesheet" href="aset/DataTables/datatables.min.css">

    <!-- Add custom CSS here -->
    <link rel="stylesheet" href="aset/css/sb-admin.css">
    <link rel="stylesheet" href="aset/font-awesome/css/font-awesome.min.css">
  </head>

  <body>
    <div id="wrapper">

      <!-- Sidebar -->
      <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
        <!-- Brand and toggle get grouped for better mobile display -->
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="">Monitoring Listrik</a>
        </div>

        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse navbar-ex1-collapse">
          <ul class="nav navbar-nav side-nav">
            <li><a href="?page=dashboard"><i class="fa fa-home"></i> Dashboard</a></li>
            <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="fa fa-code-fork"></i> Node 1 <b class="caret"></b></a>
              <ul class="dropdown-menu">
                <li><a href="?page=Tabel Listrik"><i class="fa fa-table"></i> Tabel Listrik</a></li>
                <li><a href="?page=Grafik Tegangan">Grafik Tegangan</a></li>
                <li><a href="?page=Grafik Arus">Grafik Arus Listrik</a></li>
                <li><a href="?page=Grafik Frekuensi">Grafik Frekuensi</a></li>
                <li><a href="?page=Grafik Power Factor">Grafik Power Factor</a></li>
                <li><a href="?page=Grafik Daya">Grafik Daya Aktif</a></li>
              </ul>
            </li>
            <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="fa fa-code-fork"></i> Node 2 <b class="caret"></b></a>
              <ul class="dropdown-menu">
                <li><a href="?page=Tabel Listrik2"><i class="fa fa-table"></i> Tabel Listrik</a></li>
                <li><a href="?page=Grafik Tegangan2">Grafik Tegangan</a></li>
                <li><a href="?page=Grafik Arus2">Grafik Arus Listrik</a></li>
                <li><a href="?page=Grafik Frekuensi2">Grafik Frekuensi</a></li>
                <li><a href="?page=Grafik Power Factor2">Grafik Power Factor</a></li>
                <li><a href="?page=Grafik Daya2">Grafik Daya Aktif</a></li>
              </ul>
            </li>
          </ul>

          <ul class="nav navbar-nav navbar-right navbar-user">
            <li class="dropdown user-dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="fa fa-user"></i> Aditya Pratama <b class="caret"></b></a>
              <ul class="dropdown-menu">
                <li><a href="logout.php"><i class="fa fa-power-off"></i> Log Out</a></li>
              </ul>
            </li>
          </ul>
        </div>
        <!-- /.navbar-collapse -->
      </nav>

      <div id="page-wrapper">

        <?php
          if(@$_GET['page'] == 'dashboard' || @$_GET['page'] == ''){
          include"views/dashboard.php";
          } else if (@$_GET['page'] == 'Tabel Listrik'){
            include "views/Node1/tabel listrik.php";
          } else if (@$_GET['page'] == 'Grafik Tegangan'){
            include "views/Node1/grafik_tegangan.php";
          } else if (@$_GET['page'] == 'Grafik Arus'){
            include "views/Node1/grafik_arus.php";
          } else if (@$_GET['page'] == 'Grafik Frekuensi'){
            include "views/Node1/grafik_frekuensi.php";
          } else if (@$_GET['page'] == 'Grafik Power Factor'){
            include "views/Node1/grafik_powerfactor.php";
          } else if (@$_GET['page'] == 'Grafik Daya'){
            include "views/Node1/grafik_daya.php";
          } else if (@$_GET['page'] == 'Tabel Listrik2'){
            include "views/Node2/tabel listrik2.php";
          } else if (@$_GET['page'] == 'Grafik Tegangan2'){
            include "views/Node2/grafik_tegangan2.php";
          } else if (@$_GET['page'] == 'Grafik Arus2'){
            include "views/Node2/grafik_arus2.php";
          } else if (@$_GET['page'] == 'Grafik Frekuensi2'){
            include "views/Node2/grafik_frekuensi2.php";
          } else if (@$_GET['page'] == 'Grafik Power Factor2'){
            include "views/Node2/grafik_powerfactor2.php";
          } else if (@$_GET['page'] == 'Grafik Daya2'){
            include "views/Node2/grafik_daya2.php";
          }
        ?>

      </div><!-- /#page-wrapper -->

    </div><!-- /#wrapper -->

    <!-- JavaScript -->
    <script src="aset/js/jquery-3.4.0.min.js"></script>
    <script src="aset/js/bootstrap.js"></script>
    <script src="aset/DataTables/datatables.min.js"></script>

  </body>
</html>