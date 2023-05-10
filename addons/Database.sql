--
-- File generated with SQLiteStudio v3.4.3 on qua. mai. 10 11:07:20 2023
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: Building
DROP TABLE IF EXISTS Building;

CREATE TABLE IF NOT EXISTS Building (
    CompanyCNPJ INTEGER,
    ClientCNPJ  TEXT,
    Name        TEXT    DEFAULT "",
    Price       REAL    DEFAULT (0),
    StartDate   TEXT    DEFAULT "",
    EndDate     TEXT    DEFAULT "",
    PRIMARY KEY (
        ClientCNPJ,
        CompanyCNPJ
    ),
    FOREIGN KEY (
        CompanyCNPJ
    )
    REFERENCES ConstructionCompany (CNPJ) ON DELETE CASCADE,
    FOREIGN KEY (
        ClientCNPJ
    )
    REFERENCES ClientLegal (CNPJ) ON DELETE CASCADE
);


-- Table: ClientLegal
DROP TABLE IF EXISTS ClientLegal;

CREATE TABLE IF NOT EXISTS ClientLegal (
    CNPJ           TEXT,
    Name           TEXT,
    PhoneNumber    TEXT,
    ZipCode        TEXT,
    OccupationArea TEXT,
    Avaliation     REAL,
    PRIMARY KEY (
        CNPJ
    )
);


-- Table: ClientPhysical
DROP TABLE IF EXISTS ClientPhysical;

CREATE TABLE IF NOT EXISTS ClientPhysical (
    CPF               TEXT,
    Name              TEXT,
    PhoneNumber       TEXT,
    Income            REAL,
    CompanyCNPJ       TEXT DEFAULT "",
    BuildingName      TEXT DEFAULT "",
    BuildingPrice     REAL DEFAULT (0),
    BuildingStartDate TEXT DEFAULT "",
    BuildingEndDate   TEXT DEFAULT "",
    PRIMARY KEY (
        CPF
    ),
    FOREIGN KEY (
        CompanyCNPJ
    )
    REFERENCES ConstructionCompany (CNPJ) 
);


-- Table: ConstructionCompany
DROP TABLE IF EXISTS ConstructionCompany;

CREATE TABLE IF NOT EXISTS ConstructionCompany (
    CNPJ        TEXT,
    Name        TEXT,
    Zip         TEXT,
    PhoneNumber TEXT,
    Avaliation  REAL,
    PRIMARY KEY (
        CNPJ
    )
);


COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
