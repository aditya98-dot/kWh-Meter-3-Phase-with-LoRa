<?php
  session_start();
  if(empty($_SESSION['akses'])){
    echo "
        <script>
        alert('Mohon untuk login terlebih dahulu');
        window.location.href='index.php';
        </script>
    ";
  }
?>

<!DOCTYPE html>
<html>
	<head>
		<title></title>
		  <link href="//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css" rel="stylesheet">
		  <link href="https://fonts.googleapis.com/css?family=Roboto" rel="stylesheet">
		  <link rel="stylesheet" href="aset/css/dashboard.css">
		  <link rel="stylesheet" href="aset/css/bootstrap.css">

		  <!-- Add custom CSS here -->
		  <link rel="stylesheet" href="aset/css/sb-admin.css">
		  <link rel="stylesheet" href="aset/font-awesome/css/font-awesome.min.css">
	</head>

	<body>
		<div class="row">
		  <div class="col-lg-12">
		    <h1>Monitoring Listrik <small>Monalisa ~Monitoring Listrik 3 Fasa~</small></h1>
		    <ol class="breadcrumb">
		      <li class="active"><i class="fa fa-home"></i> Dashboard <?php
		      $_SESSION['akses']; ?></li>
		    </ol>
		  </div>
		</div>

		<div class="row">
			 <div class="col-lg-12">
			 	<div style="text-align: center;">
					<img src="img/gambar3.png" class="img-fluid" style="height: 275px; width: 400px;">
				</div>
		        <h3 class="align-center">Deskripsi Alat</h3>
		        	<font size="4", face="Times New Roman"><p class="align-justify">Monalisa merupakan alat yang didesain untuk memonitoring besaran listrik yang dilengkapi dengan pembacaan besaran listrik dan sistem informasi kepada pengguna energi listrik. Monalisa sendiri terfokus untuk memonitoring besaran listrik sistem 3 fasa yang meliputi tegangan, arus listrik, frekuensi listrik, faktor daya, dan daya aktif. Alat ini terdiri dari dua node, yaitu node transmitter (berfungsi untuk mengirimkan data pengukuran besaran listrik) dan receiver (berfungsi menerima data dari node transmitter dan mengirimkan data tersebut ke database). Pada pemasangan alat ini node transmitter diletakan pada panel listrik, sedangkan node receiver diletakkan dekat dengan data center yang tersedia. pengiriman data pada kedua node ini berbasis Wireless Sensor Network dengan memanfaatkan teknologi LoRa untuk mentransmissikan data dari node transmitter ke node receiver.<br><br> Monalisa sendiri kepanjangan dari MONITORING LISTRIK 3 FASA. Alat ini dapat mengukur tegangan, arus listrik, frekuensi listrik, power factor, dan daya aktif pada sistem listrik 3 fasa dengan periode setiap 15 menit sekali. Hal spesial dari alat ini adalah terdapat modul micro SD card sehingga data yang diukur juga di backup pada micro SD sehingga jika terjadi koneksi internet terputus backup data tersedia pada modul micro SD card tersebut. Sistem informasi monalisa kepada pengguna energi listrik memanfaatkan teknologi IoT (Internet of Things) sehingga hasil pengukuran alat ini dapat di akses melalui halaman web monitoring tanpa harus mengukur langsung ke panel listrik.
		        <p>

		        <br><br>
		   </div>
		</div>


	  <!-- Footer -->
	  <footer>
	    <div class="container">
	      <div class="row">
	        <div class="col-lg-5 col-md-5 col-sm-4 col-xs-12">
	          <ul class="adress">
	            <span>Find Me</span>
	            <div class="align-justify">
	              <li>
	                <p>If you are interested about the internet of things, electrical, or related fields, I would love to discuss it and you can reach me on:</p>
	              </li>
	            </div>
	            <li>
	              <p>+62853 3338 9189</p>
	            </li>
	          </ul>
	        </div>
	        <div class="col-lg-5 col-md-5 col-sm-4 col-xs-12">
	          <ul class="social">
	            <span>Social</span>
	            <li>
	              <a href="https://github.com/aditya98-dot"><i class="fa fa-github fa-2x"></i></a>
	            </li>
	            <li>
	              <a href="https://www.linkedin.com/in/aditya-prtm98"><i class="fa fa-linkedin fa-2x"></i></a>
	            </li>
	            <li>
	              <a href="mailto:adityapratama141198@gmail.com"><i class="fa fa-envelope fa-2x"></i></a>
	            </li>
	          </ul>
	        </div>
	      </div>
	    </div>
	  </footer>

	</body>
</html>
