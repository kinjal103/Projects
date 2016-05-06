<?php
session_start();
if(!is_numeric($_SESSION['team_no']))
{
	header("location: index.php");
}
if(isset($_SESSION['error']))
{
	echo $_SESSION['error'];
	unset($_SESSION['error']);
}
$con = mysql_connect("localhost","root","");
$db = mysql_select_db("beer_db");
$team_no = $_SESSION['team_no'];
$result = mysql_query("SELECT * FROM `distributor"."$team_no"."`");
$cur_week_arr = mysql_fetch_array(mysql_query("SELECT `week` FROM `current_week`"));
$cur_week = $cur_week_arr['week'];
$inp_ord_res = mysql_query("SELECT `order_out` FROM `wholesaler"."$team_no"."` WHERE `order_out_week`='$cur_week'");
if(mysql_num_rows($inp_ord_res)>0)
{
	$inp_ord_arr = mysql_fetch_array($inp_ord_res);
	$inp_ord = $inp_ord_arr['order_out'];
}
else
{
	$inp_ord = 0;
}
$inp_del_res = mysql_query("SELECT `del_out` FROM `factory"."$team_no"."` WHERE `del_out_week`='$cur_week'");
if(mysql_num_rows($inp_del_res)>0)
{
	$inp_del_arr = mysql_fetch_array($inp_del_res);
	$inp_del = $inp_del_arr['del_out'];
}
else
{
	$inp_del = 0;
}
if(mysql_num_rows($result)>0)
{
	echo "<center><table border='medium'><tr><th>Week</th><th>Order In</th><th>Order Out</th><th>Delivery In</th><th>Delivery Out</th><th>Available</th><th>Cost per Week</th><th>Total cost</th></tr>";
	while(($result_arr = mysql_fetch_array($result)))
	{
		echo "<tr><td>{$result_arr['week']}</td><td>{$result_arr['order_in']}</td>";
		echo "<td>{$result_arr['order_out']}</td><td>{$result_arr['del_in']}</td>";
		echo "<td>{$result_arr['del_out']}</td><td>{$result_arr['available']}</td>";
		echo "<td>{$result_arr['current_week_cost']}</td><td>{$result_arr['total_cost']}</td></tr>";
	}
	echo "</table></center>";
}
else
{
	//$admin_cust = mysql_fetch_array(mysql_query("SELECT * FROM `admin_customer`"));
	echo "<center>First week</center>";
	$check = mysql_fetch_array(mysql_query("SELECT * FROM `teams` WHERE `team_no`='$team_no'"));
	if($check['distributor']==0)
	{
		mysql_query("UPDATE `teams` SET `distributor`='1' WHERE `team_no`='$team_no'");
		$check = mysql_fetch_array(mysql_query("SELECT * FROM `teams` WHERE `team_no`='$team_no'"));
		if(($check['retailer']==1)&&($check['wholesaler']==1)&&($check['factory']==1))
		{
			mysql_query("UPDATE `teams` SET `full`='1' WHERE `team_no`='$team_no'");
		}
	}
	else
	{
		$_SESSION['error'] = "Role not available!";
		header("location: index.php");
		die();
	}
}
echo "<center><table><tr><th>Current Order</th><td>$inp_ord</td></tr></table></center>";
echo "<center><table><tr><th>Current Delievery</th><td>$inp_del</td></tr></table></center>";
?>

<html>
<head>
<title>Distributor</title>
</head>

<body>
<br/>
<form action="distributor_backend.php" method="post"><center>
<table>
<tr><td>Order to factory:</td>
<td><input type="number" size="10" name="order_out"/></td></tr>
<tr><td>Delivery to Wholesaler:</td>
<td><input type="number" size="10" name="del_out"/></td></tr>
<tr><td colspan="2"><center><input type="Submit"/></center></td></tr>
</table>
</center>
<?php echo "<input type='hidden' value='$team_no' name='team_no'/>";?>
</form>
</body>
</html>