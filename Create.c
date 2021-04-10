Create()
{
	/* Flights */

	web_url("Search Flights Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_ex(
		"ParamName=OFlight",
    	"LB=name=\"outboundFlight\" value=\"",
    	"RB=\"",
    	"Ordinal=all",
    	"NotFound=Warning",
			LAST);
	
	
	web_reg_save_param_ex(
		"ParamName=PriceTickets",
    	"LB=td align=\"center\">$ ",
    	"RB=<\/TD>",
    	"Ordinal=all",
    	"NotFound=Warning",
		LAST);
	
	
	/* Continue 1 */
	
	web_submit_data("reservations.pl", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={DepartureCity}", ENDITEM, 
		"Name=departDate", "Value={DateOut}", ENDITEM, 
		"Name=arrive", "Value={ArrivalCity}", ENDITEM, 
		"Name=returnDate", "Value={DateTo}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={PrefSeat}", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=62", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	
	
	
	ticket[1]=atoi(lr_eval_string("{PriceTickets_1}"));
	ticket[2]=atoi(lr_eval_string("{PriceTickets_2}"));
	ticket[3]=atoi(lr_eval_string("{PriceTickets_3}"));
	ticket[4]=atoi(lr_eval_string("{PriceTickets_4}"));
	
	lr_output_message("���� 1 ������ = %d",ticket[1]);
	lr_output_message("���� 2 ������ = %d",ticket[2]);
	lr_output_message("���� 3 ������ = %d",ticket[3]);
	lr_output_message("���� 4 ������ = %d",ticket[4]);
	
	flight[1]=lr_eval_string("{OFlight_1}");
	flight[2]=lr_eval_string("{OFlight_2}");
	flight[3]=lr_eval_string("{OFlight_3}");
	flight[4]=lr_eval_string("{OFlight_4}");
	
	lr_output_message("�������� outboundFlight 1 = %s",flight[1]);
	lr_output_message("�������� outboundFlight 2 = %s",flight[2]);
	lr_output_message("�������� outboundFlight 3 = %s",flight[3]);
	lr_output_message("�������� outboundFlight 4 = %s",flight[4]);
	
	
	/* �������� �������� ���� ������*/
	for(i;i<=4;i++){
		if(ticket[i]%2==0){
			trueticket[k++] = flight[i];      /*���������� ������� � ������ ����� � ������*/            
			j++;
		}
	}
	
	if(j==0){
		lr_output_message("������� � ������ ����� ���, ������ ��������, ����� �� ������");
	} else{
	
	lr_output_message("���������� ������� � ������ ����� = %d",j);
	
	i = 1;
	for(i;i<k;i++){
		lr_output_message("�������� outboundFlight ������ � ������ ����� = %s",trueticket[i]);
	}

	srand(time(NULL));
  	randomize = rand() % j + 1;
  	lr_save_string(trueticket[randomize],"true");
 	lr_output_message("��������� ����� ������ �� ����� ������ = %d",randomize);
 	lr_output_message("������ ���� ����� = %s",trueticket[randomize]);
	
	web_submit_data("reservations.pl_2", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={true}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=seatPref", "Value={PrefSeat}", ENDITEM, 
		"Name=reserveFlights.x", "Value=71", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);
	

	/* Continue 3 */
	
	web_reg_save_param_ex(
		"ParamName=Info",
    	"LB=          ",
    	"RB=\.<br>",
    	"Ordinal=1",
    	"NotFound=Warning",
		LAST);
	
	
	web_submit_data("reservations.pl_3", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=seatPref", "Value={PrefSeat}", ENDITEM, 
		"Name=outboundFlight", "Value={true}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=39", ENDITEM, 
		"Name=buyFlights.y", "Value=12", ENDITEM, 
		LAST);
	infot[1]=lr_eval_string("{Info}");
	lr_output_message("���������� � ������: = %s", infot[1]);
	
	}
	
	return 0;
}
