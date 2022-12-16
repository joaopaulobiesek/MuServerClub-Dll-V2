require('AccController\\Config')
if HWIDLimit.Switch ~= nil and HWIDLimit.Switch ~= false then
    BridgeFunctionAttach('OnCharacterEntry',"HWIDLimit_OnCharacterEntry")
	BridgeFunctionAttach('OnSQLAsyncResult',"HWIDLimit_OnSQLAsyncResult")
	BridgeFunctionAttach('OnUserRespawn',"HWIDLimit_OnUserRespawn")
	BridgeFunctionAttach2('OnMapChange',"HWIDLimit_OnMapChange")
	local ServerNameAcc = ConfigReadString('GameServerInfo','ServerName','DATA/GameServerInfo - Common.dat')	
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
				
			    if HWIDLimit.MaxConnect > 0 and count > HWIDLimit.MaxConnect then
			
				    NoticeSend(aIndex,3,HWIDLimit.stringsMax[GetObjectLang(aIndex)+1])
				    NoticeSend(aIndex,3,HWIDLimit.stringsMax2[GetObjectLang(aIndex)+1])							
				    --MoveUser(aIndex,333)
					local y = HWIDLimit.AuthY + RandomGetNumber((HWIDLimit.AuthY+9)-HWIDLimit.AuthY+1) 
	                MoveUserEx(aIndex,HWIDLimit.AuthMapMove,HWIDLimit.AuthX,y)
					
			    else
			
				    NoticeSend(aIndex,3,strings[GetObjectLang(aIndex)+1])
				
			    end		
			
			end
		
		end
		
		return 1
	
	end
	
	return 0

end

F_InArray = function(aValue, bValue)
	
	local inarray = -1
	
	for index, value in pairs(bValue) do
		
		if tonumber(aValue) ~= nil and tonumber(value) ~= nil then
			
			if tonumber(value) == tonumber(aValue) then
				inarray = index
				break
			end
			
		else
			
			if value == aValue then
				inarray = index
				break
			end
			
		end
		
	end
	
	return inarray
end

HWIDLimit_OnCharacterEntry = function(aIndex)
	
	SQLQuery(string.format("UPDATE Character SET MapNumber = %d WHERE Name = '%s'",GetObjectMap(aIndex),GetObjectName(aIndex)))
    SQLClose()
	if GetObjectConnected(aIndex) == 3 then
        SQLAsyncQuery(string.format("UPDATE MEMB_STAT SET ServerName2='%s' WHERE memb___id='%s'",ServerNameAcc,GetObjectAccount(aIndex)))
    end
	if GetObjectConnected(aIndex) == 3 and GetObjectAccountLevel(aIndex) < HWIDLimit.AuthVip and F_InArray(GetObjectAccount(aIndex),HWIDLimit.AuthAcc) == -1 and F_InArray(GetObjectMap(aIndex),HWIDLimit.AuthMap) == -1 then
        if 	HWIDLimit.CheckServerName == 1 then	
	        SQLAsyncQuery(string.format("SELECT COUNT(1) as count FROM memb_info m LEFT JOIN memb_stat s on s.memb___id=m.memb___id LEFT JOIN AccountCharacter a on a.Id = s.memb___id LEFT JOIN Character c on c.Name = a.gameidc WHERE m.hwid = (select hwid from memb_info where memb___id='%s') and s.ServerName2 = '%s' and s.ConnectStat = 1 and m.AccountLevel < %d and c.MapNumber not in (%s)",GetObjectAccount(aIndex),ServerNameAcc,HWIDLimit.AuthVip,HWIDLimit.AuthMapSql),"HWIDLimit_OnSQLAsyncResult_1",string.format("%d",aIndex))
		else	
            SQLAsyncQuery(string.format("SELECT COUNT(1) as count FROM memb_info m LEFT JOIN memb_stat s on s.memb___id=m.memb___id LEFT JOIN AccountCharacter a on a.Id = s.memb___id LEFT JOIN Character c on c.Name = a.gameidc WHERE m.hwid = (select hwid from memb_info where memb___id='%s') and s.ConnectStat = 1 and m.AccountLevel < %d and c.MapNumber not in (%s)",GetObjectAccount(aIndex),HWIDLimit.AuthVip,HWIDLimit.AuthMapSql),"HWIDLimit_OnSQLAsyncResult_1",string.format("%d",aIndex))
        end	
	end
	
end

HWIDLimit_OnMapChange = function(aIndex)

    SQLQuery(string.format("UPDATE Character SET MapNumber = %d WHERE Name = '%s'",GetObjectMap(aIndex),GetObjectName(aIndex)))
	SQLClose()

	if GetObjectConnected(aIndex) == 3 and GetObjectAccountLevel(aIndex) < HWIDLimit.AuthVip and F_InArray(GetObjectAccount(aIndex),HWIDLimit.AuthAcc) == -1 and F_InArray(GetObjectMap(aIndex),HWIDLimit.AuthMap) == -1  then
        if 	HWIDLimit.CheckServerName == 1 then	
	        SQLAsyncQuery(string.format("SELECT COUNT(1) as count FROM memb_info m LEFT JOIN memb_stat s on s.memb___id=m.memb___id LEFT JOIN AccountCharacter a on a.Id = s.memb___id LEFT JOIN Character c on c.Name = a.gameidc WHERE m.hwid = (select hwid from memb_info where memb___id='%s') and s.ServerName2 = '%s' and s.ConnectStat = 1 and m.AccountLevel < %d and c.MapNumber not in (%s)",GetObjectAccount(aIndex),ServerNameAcc,HWIDLimit.AuthVip,HWIDLimit.AuthMapSql),"HWIDLimit_OnSQLAsyncResult_1",string.format("%d",aIndex))
		else	
            SQLAsyncQuery(string.format("SELECT COUNT(1) as count FROM memb_info m LEFT JOIN memb_stat s on s.memb___id=m.memb___id LEFT JOIN AccountCharacter a on a.Id = s.memb___id LEFT JOIN Character c on c.Name = a.gameidc WHERE m.hwid = (select hwid from memb_info where memb___id='%s') and s.ConnectStat = 1 and m.AccountLevel < %d and c.MapNumber not in (%s)",GetObjectAccount(aIndex),HWIDLimit.AuthVip,HWIDLimit.AuthMapSql),"HWIDLimit_OnSQLAsyncResult_1",string.format("%d",aIndex))
        end	
	end

end

HWIDLimit_OnUserRespawn = function(aIndex,Type)

	if GetObjectAccountLevel(aIndex) == 3 and GetObjectOfflineFlag(aIndex) == 1 and F_InArray(GetGameServerCode(),HWIDLimit.ServerCodeDeath) == -1 then
	
		if F_InArray(GetObjectMap(aIndex),HWIDLimit.ServerCodeMapDeath) == -1 then
		
			MoveUserEx(aIndex,GetObjectDeathMap(aIndex),GetObjectDeathMapX(aIndex),GetObjectDeathMapY(aIndex))
			
		end
		
	end

end