vuser_end()
{
	tName = "007.Log_out_ex2";
	lr_start_transaction(tName);

	web_url("SignOff Button", 
		"URL={Host}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status); 
	
	return 0;
}
