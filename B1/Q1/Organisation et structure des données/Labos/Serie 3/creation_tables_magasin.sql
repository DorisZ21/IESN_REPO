/*
CREATE DATABASE serie3;

CREATE TABLE categorie(
	numero numeric(3) PRIMARY KEY,
	nom varchar(20) NOT NULL
);

INSERT INTO categorie (numero, nom)
VALUES
(1,'fruit'),
(2,'légume'),
(3,'viande'),
(4,'boulangerie'),
(5,'crémerie');

UPDATE categorie SET nom = 'boucherie' WHERE numero = 3;

DELETE FROM categorie WHERE numero = 5;

DELETE FROM categorie;

DROP TABLE categorie;

CREATE TABLE produit(
 reference varchar(5) PRIMARY KEY,
 libelle varchar(30) NOT NULL,
 prix decimal(6,1),
 est_dans_frigo bit NOT NULL,
 nb_calories numeric(5),
 poids numeric(7),
 numeroCategorie numeric(3) NOT NULL,
 FOREIGN KEY (numeroCategorie) REFERENCES categorie(numero)

);

INSERT INTO produit (reference,libelle,prix,est_dans_frigo,nb_calories,poids,numeroCategorie)
VALUES
('Ban','Banane',1.3,0,89,1000,1),
('CAR','Carotte',0.9,0,41,500,2),
('GaCh','Gâteau au chocolat',23.9,1,NULL,NULL,4),
('JaPa','Jambon de Pame',8.9,1,NULL,100,3),
('POM','Pomme',0.6,0,52,NULL,1);

update produit set numeroCategorie = 2 WHERE reference = 'Ban';

alter table produit alter column libelle varchar(50);
alter table produit alter column prix numeric(5,2);
alter table produit add date_creation date;

insert into produit (reference,libelle,prix,est_dans_frigo,numeroCategorie,date_creation)
values ('CrFr','Crème fraîche',4.56,1,5,'2020-02-21');

update produit set date_creation= '2022-12-31' WHERE reference = 'GaCh';

alter table produit add check(prix >= 0);

*/

create table section(
	code varchar(10) primary key,
	libelle varchar(10)
);

create table localite(
	numero numeric(3) primary key,
	code_postal numeric(6) unique,
	nom varchar(30) unique
);

create table etudiant(
	matricule numeric primary key,
	prenom varchar(50) not null,
	nom varchar(50) not null,
	date_naissance date,
	email varchar(320) unique,
	codeSection varchar (10),
	foreign key(codeSection) references section(code),
	numero_dans_rue numeric(3) NOT NULL,
	nom_de_rue varchar(50) NOT NULL,
	numeroLocalite numeric(3)
	foreign key(numeroLocalite) references localite(numero)
)


