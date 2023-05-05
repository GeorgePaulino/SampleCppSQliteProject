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
	FOREIGN KEY("ClientCNPJ") REFERENCES "ClientLegalPerson"("CNPJ") ON DELETE CASCADE
);
DROP TABLE IF EXISTS "ClientLegalPerson";
CREATE TABLE IF NOT EXISTS "ClientLegalPerson" (
	"CNPJ"	TEXT,
	"Name"	TEXT,
	"PhoneNumber"	TEXT,
	"ZipCode"	TEXT,
	"OccupationArea"	TEXT,
	"Avaliation"	REAL,
	PRIMARY KEY("CNPJ")
);
DROP TABLE IF EXISTS "ClientPhysicalPerson";
CREATE TABLE IF NOT EXISTS "ClientPhysicalPerson" (
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
