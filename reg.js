function vanish(i)
{
	if(i.value==i.defaultValue)
	{
		i.value="";
		i.style.color="#000";
	}
}
function reappear(i)
{
	if(i.value=="")
	{
		i.value=i.defaultValue;
		i.style.color="#888";
	}
}
function more_quiz()
{
	if(main_form.st_first_name.value=="First name")
	{
		alert("Please Type your name");
		return false;
	}
	if(main_form.number2.value=="")
	{
		alert("Please fill in your mobile number");
		return false;
	}
	if(main_form.mail.value=="Email Address")
	{
		alert("Please enter you Email ID");
		return false;
	}
	else
	{
		window.open("more_q.html","","");
		return true;
	}
}