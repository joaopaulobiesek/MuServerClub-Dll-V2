HWIDLimit = {
	Switch = true, -- true > ativa | false > desativa
	MaxConnect = 5, -- numero m�ximo de conex�es simult�near permitida
	AuthAcc = {}, -- Acc permitidas
	AuthVip = 2, -- Nivel de VIP
	AuthMap = {0,2,3,79},
    AuthMapSql = "0,2,3,79", -- Mapas que n�o iram contar numero de player 
    AuthMapMove = 79, -- Excede Numero maximo move o player para este mapa 
    AuthX = 56, -- Excede Numero maximo move o player para esta coordenada
    AuthY = 65, -- Excede Numero maximo move o player para esta coordenada
	CheckServerName = 0, -- 0 desativa | 1 Ativa verifica��o de ServerName2 (Nescessario Tabela + ServerDll)
    ServerCodeDeath = {0,17}, --Server Code Que o sistema n�o ira funcionar!
    ServerCodeMapDeath = {63}, --Mapa que server Code n�o ira funcionar!
	strings = {
            [1] = "Max connected accounts",
            [2] = "Maximo de contas conectadas",
            [3] = "Cuentas conectadas m�ximas",
    },
	stringsMax = {
            [1] = "You were moved to the market because",
            [2] = "Voc� foi movido para o mercado por que",
            [3] = "Te trasladaron al mercado porque",
    },
	stringsMax2 = {
            [1] = "exceeded the simultaneous character limit",
            [2] = "excedeu o limite de personagem simult�neas",
            [3] = "super� el l�mite de caracteres simult�neos",
    }
	
}