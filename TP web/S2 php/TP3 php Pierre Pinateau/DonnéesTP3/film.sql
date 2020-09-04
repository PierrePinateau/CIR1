CREATE TABLE genre (
    id     int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    genre  varchar(50) NOT NULL
);

CREATE TABLE realisateur (
    id     int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    nom    varchar(50) NOT NULL,
    prenom varchar(50),
    datenaissance date,
	sexe   char(1) CHECK (sexe IN ('h','f'))
);

CREATE TABLE film (
    id            int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    titre         varchar(100) NOT NULL,
    anneesortie   int,
	idrealisateur int NOT NULL REFERENCES realisateur(id)
);

CREATE TABLE genrefilm (
    id      int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    idfilm  int NOT NULL REFERENCES film(id),
	idgenre int NOT NULL REFERENCES genre(id)
);

CREATE TABLE repliquescultes (
    id       SERIAL PRIMARY KEY,
    replique varchar(500) NOT NULL,
	idfilm   int NOT NULL REFERENCES film(id)
);

INSERT INTO genre (genre) VALUES ('Comédie');
INSERT INTO genre (genre) VALUES ('Drame');
INSERT INTO genre (genre) VALUES ('Thriller');
INSERT INTO genre (genre) VALUES ('Action');
INSERT INTO genre (genre) VALUES ('Western');
INSERT INTO genre (genre) VALUES ('Horreur');

INSERT INTO realisateur (nom, prenom, datenaissance, sexe) VALUES ('Tarantino','Quentin','1963-03-27','h');

INSERT INTO film (titre, anneesortie, idrealisateur) VALUES ('Pulp Fiction',1994,1);

INSERT INTO genrefilm (idfilm, idgenre) VALUES (1,3);
INSERT INTO genrefilm (idfilm, idgenre) VALUES (1,4);

INSERT INTO repliquescultes (replique, idfilm) VALUES ('Jules : Vincent... regarde la taille de ce flingue ! Il est plus gros que le bonhomme !!',1);
INSERT INTO repliquescultes (replique, idfilm) VALUES ('Fabienne : J''aime que tu m''appelles Tulipe c''est beaucoup plus sympa que mongolienne.',1);
INSERT INTO repliquescultes (replique, idfilm) VALUES ('Winston Wolfe : C''est à une demi-heure d''ici. J''y suis dans dix minutes. Narrateur : Et neuf minutes trente sept secondes plus tard...',1);
INSERT INTO repliquescultes (replique, idfilm) VALUES ('Mia : Je vais me repoudrer le nez.',1);
