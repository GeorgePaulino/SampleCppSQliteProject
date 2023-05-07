BEGIN TRANSACTION;
DROP TABLE IF EXISTS "Building";
CREATE TABLE IF NOT EXISTS "Building" (
	"CompanyCNPJ"	INTEGER,
	"ClientCNPJ"	TEXT,
	"Price"	REAL,
	"Name"	TEXT,
	"StartDate"	TEXT,
	"EndDate"	TEXT,
	PRIMARY KEY("ClientCNPJ","CompanyCNPJ"),
	FOREIGN KEY("CompanyCNPJ") REFERENCES "ConstructionCompany"("CNPJ") ON DELETE CASCADE,
	FOREIGN KEY("ClientCNPJ") REFERENCES "ClientLegal"("CNPJ") ON DELETE CASCADE
);
DROP TABLE IF EXISTS "ClientLegal";
CREATE TABLE IF NOT EXISTS "ClientLegal" (
	"CNPJ"	TEXT,
	"Name"	TEXT,
	"PhoneNumber"	TEXT,
	"ZipCode"	TEXT,
	"OccupationArea"	TEXT,
	"Avaliation"	REAL,
	PRIMARY KEY("CNPJ")
);
DROP TABLE IF EXISTS "ClientPhysical";
CREATE TABLE IF NOT EXISTS "ClientPhysical" (
	"CPF"	TEXT,
	"Name"	TEXT,
	"PhoneNumber"	TEXT,
	"Income"	REAL,
	"CompanyCNPJ"	TEXT,
	"BuildingName"	TEXT,
	"BuildingStartDate"	TEXT,
	"BuildingEndDate"	TEXT,
	PRIMARY KEY("CPF"),
	FOREIGN KEY("CompanyCNPJ") REFERENCES "ConstructionCompany"("CNPJ")
);
DROP TABLE IF EXISTS "ConstructionCompany";
CREATE TABLE IF NOT EXISTS "ConstructionCompany" (
	"CNPJ"	TEXT,
	"Name"	TEXT,
	"PhoneNumber"	TEXT,
	"Avaliation"	REAL,
	PRIMARY KEY("CNPJ")
);
COMMIT;
