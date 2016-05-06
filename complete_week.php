<?php
session_start();
$db = mysql_connect("localhost","root","");
mysql_select_db("beer_db");
$cur_role = $_GET['cur_role'];
$team_no = $_SESSION['team_no'];
set_time_limit(0);
function execute_query ($query)
{
	$result = mysql_fetch_array(mysql_query($query));
	return $result['week'];
}
$dis = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='distributor'");
$who = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='wholesaler'");
$fac = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='factory'");
$ret = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='retailer'");
while (($dis==0)||($who==0)||($fac==0)||($ret==0))
{
	$dis = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='distributor'");
	$who = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='wholesaler'");
	$fac = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='factory'");
	$ret = execute_query("SELECT * FROM `week_cnt"."$team_no"."` WHERE `role`='retailer'");
}
//if(strcmp($cur_role,"factory")!=0)
//{
	sleep(10);
//}
if(strcmp($cur_role,"factory")==0)
{
	$cur_week = execute_query("SELECT * FROM `current_week`");
	$prev_week = $cur_week;
	$cur_week = $cur_week + 1;
	mysql_query("UPDATE `current_week` SET `week`='$cur_week' WHERE `week`='$prev_week'");
	mysql_query("UPDATE `week_cnt"."$team_no"."` SET `week`='0' WHERE 1");
}
sleep(5);
header("location: ".$cur_role."_main.php");
die();
?>