Create()
{
	tName = "003.OpenPage_ticket_FindFlight_ex2";
	lr_start_transaction(tName);

	status=web_url("Search Flights Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	 end_transaction(tName, status);
	 
	  tName = "004.Create_ticket_FindFlight_ex2";
      lr_start_transaction(tName);

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
	
	
	status=web_submit_data("reservations.pl", 
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
	
      end_transaction(tName, status);
	
	
	
	ticket[1]=atoi(lr_eval_string("{PriceTickets_1}"));
	ticket[2]=atoi(lr_eval_string("{PriceTickets_2}"));
	ticket[3]=atoi(lr_eval_string("{PriceTickets_3}"));
	ticket[4]=atoi(lr_eval_string("{PriceTickets_4}"));
	
	lr_output_message("Цена 1 билета = %d",ticket[1]);
	lr_output_message("Цена 2 билета = %d",ticket[2]);
	lr_output_message("Цена 3 билета = %d",ticket[3]);
	lr_output_message("Цена 4 билета = %d",ticket[4]);
	
	flight[1]=lr_eval_string("{OFlight_1}");
	flight[2]=lr_eval_string("{OFlight_2}");
	flight[3]=lr_eval_string("{OFlight_3}");
	flight[4]=lr_eval_string("{OFlight_4}");
	
	lr_output_message("Значение outboundFlight 1 = %s",flight[1]);
	lr_output_message("Значение outboundFlight 2 = %s",flight[2]);
	lr_output_message("Значение outboundFlight 3 = %s",flight[3]);
	lr_output_message("Значение outboundFlight 4 = %s",flight[4]);
	
	
	/* Проверка четности цены билета*/
	for(i;i<=4;i++){
		if(ticket[i]%2==0){
			trueticket[k++] = flight[i];      /*Добавление билетов с четной ценой в массив*/            
			j++;
		}
	}
	
	if(j==0){
		lr_output_message("Билетов с четной ценой нет, скрипт завершен, билет не создан");
	} else{
	
	lr_output_message("Количество билетов с чётной ценой = %d",j);
	
	i = 1;
	for(i;i<k;i++){
		lr_output_message("Значение outboundFlight билета с чётной ценой = %s",trueticket[i]);
	}

	srand(time(NULL));
  	randomize = rand() % j + 1;
  	lr_save_string(trueticket[randomize],"true");
 	lr_output_message("Случайный номер билета из числа четных = %d",randomize);
 	lr_output_message("Выбран этот билет = %s",trueticket[randomize]);
 	
 	 tName = "005.Create_ticket_ChooseCost_ex2";
	 lr_start_transaction(tName);
	
	status=web_submit_data("reservations.pl_2", 
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
	
		end_transaction(tName, status); 
		
		tName = "006.Create_ticket_PaymentDetail_ex2";
		lr_start_transaction(tName);
	
	web_reg_save_param_ex(
		"ParamName=Info",
    	"LB=          ",
    	"RB=\.<br>",
    	"Ordinal=1",
    	"NotFound=Warning",
		LAST);
	
	
	status=web_submit_data("reservations.pl_3", 
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
		
		end_transaction(tName, status);
	infot[1]=lr_eval_string("{Info}");
	lr_output_message("Информация о билете: = %s", infot[1]);
	
	}
	
	return 0;
}
