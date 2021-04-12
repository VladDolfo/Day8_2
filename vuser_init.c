vuser_init()
{
	tName = "001.Login_open_field_ex2";
	lr_start_transaction(tName);
	
	web_reg_save_param_ex(
    	"ParamName=userSession", 
    	"LB/IC=name=\"userSession\" value=\"",
    	"RB/IC=\"",
    	"Ordinal=1",
	LAST);
	
	status=web_url("webtours", 
		"URL={Host}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
     end_transaction(tName, status);
     
      tName = "002.Login_fillin_fiels_ex_2";
	  lr_start_transaction(tName);
	

	status=web_submit_data("login.pl", 
		"Action={Host}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value=Batman", ENDITEM, 
		"Name=password", "Value=1", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=54", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);
	
	  end_transaction(tName, status);
	  
	return 0;
}
