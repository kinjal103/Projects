<?php
session_start();
if(!is_numeric($_SESSION['team_cnt']))
{
	header("location: index.php");
}
$db = mysql_connect("localhost","root","");
$team_cnt = $_POST['team_cnt'];
$cnt = 1;
mysql_select_db("beer_db");
mysql_query("DROP TABLE `admin_customer`");
mysql_query("DROP TABLE `current_week`");
mysql_query("DROP TABLE `teams`");
//echo $team_cnt;
while($cnt <= $team_cnt)
{
	mysql_query("DROP TABLE `week_cnt"."$cnt"."`");
	mysql_query("DROP TABLE `retailer"."$cnt"."`");
	mysql_query("DROP TABLE `wholesaler"."$cnt"."`");
	mysql_query("DROP TABLE `distributor"."$cnt"."`");
	mysql_query("DROP TABLE `factory"."$cnt"."`");
	$cnt = $cnt + 1;
}
session_destroy();
header("location: index.php");
?>