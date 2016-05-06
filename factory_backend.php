<?php
session_start();
if(!is_numeric($_SESSION['team_no']))
{
	header("location: index.php");
}
$db = mysql_connect("localhost","root","");
mysql_select_db("beer_db");
$d_out = $_POST['del_out'];
$team_no = $_SESSION['team_no'];
function execute_query ($query)
{
	$result = mysql_query($query);
	return $result;
}
$cur_week_arr = mysql_fetch_array(execute_query("SELECT * FROM `current_week`"));
$cur_week = $cur_week_arr['week'];
$reaching_week = $cur_week+2;
$result_o_in = execute_query("SELECT `order_out` FROM `distributor"."$team_no"."` WHERE `order_out_week` = '$cur_week'");
if($result_o_in)
{
	$o_in_arr = mysql_fetch_array($result_o_in);
	$o_in = $o_in_arr['order_out'];
}
else
{
	$o_in = 0;
	if($d_out>0)
	{
		$_SESSION['error'] = "Invalid delivery!";
		header("location: factory_main.php");
		die();
	}
}
execute_query("INSERT INTO `factory"."$team_no"."` (`week`,`del_out`,`del_out_week`,`order_in`,`pending_order`) VALUES ('$cur_week','$d_out','$reaching_week','$o_in','$pending')");
//execute_query("UPDATE `week_cnt"."$team_no"."` SET `week`='1' WHERE `role`='factory'");
$cur_role = "factory";
//header("location: complete_week.php?cur_role=factory");
header("location: wait.php?role=factory");
die();
?>