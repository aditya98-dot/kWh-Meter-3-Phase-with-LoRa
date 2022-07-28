<?php
class datalog_listrik{
 public $link='';
 function __construct($perangkat_id, $tegangan_R, $arus_R, $frekuensi_R, $PF_R, $daya_R, $tegangan_S, $arus_S, $frekuensi_S, $PF_S, $daya_S, $tegangan_T, $arus_T, $frekuensi_T, $PF_T, $daya_T, $daya_Total){
  $this->connect();
  $this->storeInDB($perangkat_id, $tegangan_R, $arus_R, $frekuensi_R, $PF_R, $daya_R, $tegangan_S, $arus_S, $frekuensi_S, $PF_S, $daya_S, $tegangan_T, $arus_T, $frekuensi_T, $PF_T, $daya_T, $daya_Total);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'monitoring_Listrik') or die('Cannot select the DB');
 }
 
 function storeInDB($perangkat_id, $tegangan_R, $arus_R, $frekuensi_R, $PF_R, $daya_R, $tegangan_S, $arus_S, $frekuensi_S, $PF_S, $daya_S, $tegangan_T, $arus_T, $frekuensi_T, $PF_T, $daya_T, $daya_Total){
  $query = "INSERT INTO datalog_listrik SET perangkat_id='".$perangkat_id."', tegangan_R='".$tegangan_R."', arus_R='".$arus_R."', frekuensi_R='".$frekuensi_R."', PF_R='".$PF_R."', daya_R='".$daya_R."', tegangan_S='".$tegangan_S."', arus_S='".$arus_S."', frekuensi_S='".$frekuensi_S."', PF_S='".$PF_S."',  daya_S='".$daya_S."', tegangan_T='".$tegangan_T."', arus_T='".$arus_T."', frekuensi_T='".$frekuensi_T."', PF_T='".$PF_T."', daya_T='".$daya_T."', daya_Total='".$daya_Total."'";
  $result = mysqli_query($this->link, $query) or die('Errant query:  '.$query);
 }
 
}
if($_GET['perangkat_id'] != '' and $_GET['tegangan_R'] != '' and $_GET['arus_R'] != '' and $_GET['frekuensi_R'] != '' and $_GET['PF_R'] != '' and $_GET['daya_R'] != '' and $_GET['tegangan_S'] != '' and $_GET['arus_S'] != '' and $_GET['frekuensi_S'] != '' and $_GET['PF_S'] != '' and $_GET['daya_T'] != '' and $_GET['tegangan_T'] != '' and $_GET['arus_T'] != '' and $_GET['frekuensi_T'] != '' and $_GET['PF_T'] != '' and $_GET['daya_T'] != '' and $_GET['daya_Total'] != ''){
 
 $datalog_listrik = new datalog_listrik ($_GET['perangkat_id'],$_GET['tegangan_R'],$_GET['arus_R'],$_GET['frekuensi_R'],$_GET['PF_R'], $_GET['daya_R'],$_GET['tegangan_S'],$_GET['arus_S'], $_GET['frekuensi_S'],$_GET['PF_S'],$_GET['daya_S'],$_GET['tegangan_T'],$_GET['arus_T'],$_GET['frekuensi_T'],$_GET['PF_T'], $_GET['daya_T'], $_GET['daya_Total']);
}
?>