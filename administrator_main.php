<html>
<head>
<script>
	
	function validate()
	{
		var arr = new Array(50);
		for(var i=1;i<51;i++){
			arr[i] = "name"+i;
		}
		form=admin_cust_form;
		//alert(admin_cust_form.name1.value);
//		alert(form.no_weeks.value);
		if(form.no_weeks.value>50 || form.no_weeks.value<=0 || form.no_weeks.value=="")
		{
			alert("Invalid Week Input\n\nClick on ? for help");
			return false;
		}
		
		if(form.no_teams.value>8 || form.no_teams.value<=0 || form.no_teams.value=="")
		{
			alert("Invalid Team Input\n\nClick on ? for help");
			return false;
		}
		
		for(i=1;i<=form.no_weeks.value;i++)
		{
			if(document.getElementById(arr[i]).value=="" || document.getElementById(arr[i]).value>4)
			{
				alert("Invalid Input " + i);
				return false;
			}
		}
		while(i<51)
		{
//			alert(document.getElementById(arr[i]).value);
			if(document.getElementById(arr[i]).value != "")
			{
				alert("Input " + i + " not required");
				return false;
			}
			i++;
		}
	}
	
	function TotalWeekHelp()
	{
		alert("Total Number of Weeks should meet following requirements:\n\n1. It should be greater than 0\n\n2. It should be less than 50 (including)");
	}
	
	function TotalTeamsHelp()
	{
		alert("Total Number of Teams should have follwing requirements:\n\n1. It should be greater than 0\n\n2. It should be less than 8 (including)");
	}
	
</script>
<style></style>
<title>Administrator Page</title>
</head>
<body>
<form action="administrator_backend.php" method="POST" name="admin_cust_form" onSubmit=" return validate()">
<table>
<tr><th>Number of total weeks for this game: </th><td><input type="number" min="1" max="50" style="width: 200px" name="no_weeks"  placeholder="Number of Weeks" min="1" max="50">&nbsp;&nbsp;&nbsp;<img src="help.png" onClick="TotalWeekHelp()"></td></tr>
<tr><th>Total number of teams playing</th><td><input type="number" min="0" max="8" style="width: 200px" name="no_teams"  placeholder="Number of Teams">&nbsp;&nbsp;&nbsp;<img src="help.png" onClick="TotalTeamsHelp()"></td></tr>
<tr><th>Week number</th><th>Order(fill only upto the week enetered above)</th></tr>
<tr><td><center>1</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="1" id="name1" placeholder="No."></center></td></tr>
<tr><td><center>2</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="2" id="name2" placeholder="No."></center></td></tr>
<tr><td><center>3</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="3" id="name3" placeholder="No."></center></td></tr>
<tr><td><center>4</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="4" id="name4" placeholder="No."></center></td></tr>
<tr><td><center>5</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="5" id="name5" placeholder="No."></center></td></tr>
<tr><td><center>6</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="6" id="name6" placeholder="No."></center></td></tr>
<tr><td><center>7</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="7" id="name7" placeholder="No."></center></td></tr>
<tr><td><center>8</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="8" id="name8" placeholder="No."></center></td></tr>
<tr><td><center>9</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="9" id="name9" placeholder="No."></center></td></tr>
<tr><td><center>10</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="10" id="name10" placeholder="No."></center></td></tr>
<tr><td><center>11</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="11" id="name11" placeholder="No."></center></td></tr>
<tr><td><center>12</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="12" id="name12" placeholder="No."></center></td></tr>
<tr><td><center>13</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="13" id="name13" placeholder="No."></center></td></tr>
<tr><td><center>14</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="14" id="name14" placeholder="No."></center></td></tr>
<tr><td><center>15</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="15" id="name15" placeholder="No."></center></td></tr>
<tr><td><center>16</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="16" id="name16" placeholder="No."></center></td></tr>
<tr><td><center>17</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="17" id="name17" placeholder="No."></center></td></tr>
<tr><td><center>18</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="18" id="name18" placeholder="No."></center></td></tr>
<tr><td><center>19</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="19" id="name19" placeholder="No."></center></td></tr>
<tr><td><center>20</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="20" id="name20" placeholder="No."></center></td></tr>
<tr><td><center>21</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="21" id="name21" placeholder="No."></center></td></tr>
<tr><td><center>22</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="22" id="name22" placeholder="No."></center></td></tr>
<tr><td><center>23</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="23" id="name23" placeholder="No."></center></td></tr>
<tr><td><center>24</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="24" id="name24" placeholder="No."></center></td></tr>
<tr><td><center>25</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="25" id="name25" placeholder="No."></center></td></tr>
<tr><td><center>26</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="26" id="name26" placeholder="No."></center></td></tr>
<tr><td><center>27</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="27" id="name27" placeholder="No."></center></td></tr>
<tr><td><center>28</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="28" id="name28" placeholder="No."></center></td></tr>
<tr><td><center>29</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="29" id="name29" placeholder="No."></center></td></tr>
<tr><td><center>30</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="30" id="name30" placeholder="No."></center></td></tr>
<tr><td><center>31</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="31" id="name31" placeholder="No."></center></td></tr>
<tr><td><center>32</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="32" id="name32" placeholder="No."></center></td></tr>
<tr><td><center>33</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="33" id="name33" placeholder="No."></center></td></tr>
<tr><td><center>34</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="34" id="name34" placeholder="No."></center></td></tr>
<tr><td><center>35</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="35" id="name35" placeholder="No."></center></td></tr>
<tr><td><center>36</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="36" id="name36" placeholder="No."></center></td></tr>
<tr><td><center>37</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="37" id="name37" placeholder="No."></center></td></tr>
<tr><td><center>38</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="38" id="name38" placeholder="No."></center></td></tr>
<tr><td><center>39</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="39" id="name39" placeholder="No."></center></td></tr>
<tr><td><center>40</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="40" id="name40" placeholder="No."></center></td></tr>
<tr><td><center>41</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="41" id="name41" placeholder="No."></center></td></tr>
<tr><td><center>42</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="42" id="name42" placeholder="No."></center></td></tr>
<tr><td><center>43</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="43" id="name43" placeholder="No."></center></td></tr>
<tr><td><center>44</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="44" id="name44" placeholder="No."></center></td></tr>
<tr><td><center>45</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="45" id="name45" placeholder="No."></center></td></tr>
<tr><td><center>46</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="46" id="name46" placeholder="No."></center></td></tr>
<tr><td><center>47</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="47" id="name47" placeholder="No."></center></td></tr>
<tr><td><center>48</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="48" id="name48" placeholder="No."></center></td></tr>
<tr><td><center>49</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="49" id="name49" placeholder="No."></center></td></tr>
<tr><td><center>50</center></td><td><center><input type="number" min="0" max="4" style="width: 100px" name="50" id="name50" placeholder="No."></center></td></tr>
<tr><td colspan="2"><center><input type="submit" value="Start Game!"></center></td></tr>
</table>
</form>
</body>
</html>