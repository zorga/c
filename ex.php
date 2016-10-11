<?php
  print_r(scandir('.'));
  include("index.php");
  file_get_contents("en_lang.php");
  file_get_contents("index.php");
  $url = './index.php';
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($curl, CURLOPT_HEADER, false);
  $data = curl_exec($curl);
  curl_close($curl);
?>
