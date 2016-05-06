<?php
session_start();
$_SESSION['team_cnt'] = $_POST['no_teams'];
$db = mysql_connect("localhost","root","");
mysql_select_db("beer_db");
$week_cnt = $_POST['no_weeks'];
$team_cnt = $_POST['no_teams'];
if(!is_numeric($team_cnt))
{
	header("location: index.php");
}
$cnt = 1;
$cur_order;
$player_cnt = 1;
mysql_query("CREATE TABLE `admin_customer` (`order_out_week` int(2), `order_out` int(1), PRIMARY KEY (`order_out_week`))");
mysql_query("CREATE TABLE `current_week` (`week` int(2), PRIMARY KEY (`week`))");
mysql_query("INSERT INTO `current_week` (`week`) VALUES ('1')");
mysql_query("CREATE TABLE `teams` (`team_no` int(2), `retailer` int(2), `wholesaler` int(2), `distributor` int(2), `factory` int(2), `full` int(2), PRIMARY KEY (`team_no`))");
while ($player_cnt <= $team_cnt)
{
	mysql_query("CREATE TABLE `week_cnt"."$player_cnt"."` (`role` varchar(20), `week` int(2), PRIMARY KEY (`role`))");
	mysql_query("CREATE TABLE `distributor"."$player_cnt"."` (`week` int(2),`order_in` int(1),`pending_order` int(3),`order_out` int(1),`del_in` int(1),`del_out` int(1),`order_out_week` int(2),`del_out_week` int(2),`available` int(3),`current_week_cost` decimal(5,2),`total_cost` decimal(5,2), PRIMARY KEY (`week`))");
	mysql_query("CREATE TABLE `wholesaler"."$player_cnt"."` (`week` int(2),`order_in` int(1),`pending_order` int(3),`order_out` int(1),`del_in` int(1),`del_out` int(1),`order_out_week` int(2),`del_out_week` int(2),`available` int(3),`current_week_cost` decimal(5,2),`total_cost` decimal(5,2), PRIMARY KEY (`week`))");
	mysql_query("CREATE TABLE `retailer"."$player_cnt"."` (`week` int(2),`order_in` int(1),`pending_order` int(3),`order_out` int(1),`del_in` int(1),`del_out` int(1),`order_out_week` int(2),`available` int(3),`current_week_cost` decimal(5,2),`total_cost` decimal(5,2), PRIMARY KEY (`week`))");
	mysql_query("CREATE TABLE `factory"."$player_cnt"."` (`week` int(2),`order_in` int(1),`pending_order` int(3),`del_out` int(1),`del_out_week` int(2), PRIMARY KEY (`week`))");
	mysql_query("INSERT INTO `week_cnt"."$player_cnt"."` (`role`,`week`) VALUES ('retailer','0')");
	mysql_query("INSERT INTO `week_cnt"."$player_cnt"."` (`role`,`week`) VALUES ('wholesaler','0')");
	mysql_query("INSERT INTO `week_cnt"."$player_cnt"."` (`role`,`week`) VALUES ('distributor','0')");
	mysql_query("INSERT INTO `week_cnt"."$player_cnt"."` (`role`,`week`) VALUES ('factory','0')");
	mysql_query("INSERT INTO `teams` (`team_no`,`retailer`,`wholesaler`,`distributor`,`factory`,`full`) VALUES ('$player_cnt','0','0','0','0','0')");
	$player_cnt = $player_cnt + 1;
}
while ($cnt <= $week_cnt)
{
	$cur_order = $_POST[''.$cnt];
	mysql_query("INSERT INTO `admin_customer` (`order_out_week`,`order_out`) VALUES ('$cnt','$cur_order')");
	$cnt = $cnt + 1;
}
header("location: game_started.php");
?>