<?php
$a=$_POST["un"];
$b=$_POST["a"];
$c=$_POST["d"];
$d=$_POST["g"];
$e=$_POST["e"];
$f=$_POST["p"];
$g=$_POST["col"];
$h=$_POST["s"];
$i=$_POST["co"];
$con=mysql_connect("localhost","root","");
mysql_select_db("codehub");
mysql_query("insert into class(un,a,d,g,e,p,col,s,co) values('$a','$b','$c','$d','$e','$f','$g','$h','$i')");
echo("Registered successfully");
include("register.php");
mysql_close($con);
?>