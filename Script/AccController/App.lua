require('AccController\\Config')
if HWIDLimit.Switch ~= nil and HWIDLimit.Switch ~= false then
	LogColor(2,"Active Script HWID")	
	SQLConnect(HWIDLimit.ODBC_DataBase,"","") -- DON�T CHANGE! UNLESS YOU HAVE OTHER ODBC NAME!
	SQLAsyncConnect(HWIDLimit.ODBC_DataBase,"","") -- DON�T CHANGE! UNLESS YOU HAVE OTHER ODBC NAME!
    BridgeFunctionAttach('OnCharacterEntry',"HWIDLimit_OnCharacterEntry")
	BridgeFunctionAttach('OnSQLAsyncResult',"HWIDLimit_OnSQLAsyncResult")
else	
	LogColor(1,"Disabled Script HWID")
end

HWIDLimit_OnSQLAsyncResult = function(label,param,result)

	if label == 'HWIDLimit_OnSQLAsyncResult_1' then
	
		if result == 1 then
		
			local count = SQLAsyncGetNumber('count')
			local aIndex = CommandGetArgNumber(param,0)
			
			if count > 0 then
			
			    local strings = {
			        [1] = string.format("%s (%d/%d)",HWIDLimit.strings[GetObjectLang(aIndex)+1],(count),HWIDLimit.MaxConnect),
				    [2] = string.format("%s (%d/%d)",HWIDLimit.strings[GetObjectLang(aIndex)+1],(count),HWIDLimit.MaxConnect),
				    [3] = string.format("%s (%d/%d)",HWIDLimit.strings[GetObjectLang(aIndex)+1],(count),HWIDLimit.MaxConnect),
                }
				
			    if count > HWIDLimit.MaxConnect then
			
				    NoticeSend(aIndex,1,HWIDLimit.strings[GetObjectLang(aIndex)+1])	
					UserGameLogout(aIndex,2)
			    else
			
				    NoticeSend(aIndex,1,strings[GetObjectLang(aIndex)+1])
				
			    end		
			
			end
		
		end
		
		return 1
	
	end
	
	return 0

end

HWIDLimit_OnCharacterEntry = function(aIndex)
	if GetObjectConnected(aIndex) == 3 and GetObjectAccountLevel(aIndex) < HWIDLimit.AuthVip then	
        SQLAsyncQuery(string.format("SELECT COUNT(1) as count FROM memb_info m LEFT JOIN memb_stat s on s.memb___id=m.memb___id WHERE m.hwid = (select hwid from memb_info where memb___id='%s') and s.ConnectStat = 1",GetObjectAccount(aIndex)),"HWIDLimit_OnSQLAsyncResult_1",string.format("%d",aIndex))
	end	
end