#include <iostream>
#include "ipv4.h"
using namespace std;
void AfficherTableau(unsigned char *tab);
int main()
{
    unsigned char adresse[4]= {192,168,1,1};
    unsigned char masque[4];
    unsigned char reseau[4];
    unsigned char diffusion[4];
    unsigned char premiereAdresse[4];
    unsigned char derniereAdresse[4];

    unsigned char AdresseParDefault[4];
    unsigned char AdresseReseauCopie[4];

    IPv4 uneAdresse(adresse, 24); // instanciation de la classe IPv4
    IPv4 uneAutreAdresse;   // appel du constructeur par défaut
    IPv4 AdresseCopie(uneAdresse);  // appel du constructeur de copie
    IPv4 Adresse3 = uneAdresse;
    Adresse3 = uneAdresse;  // opérateur d'affectation

    cout << "Adresse IPv4 : ";
    AfficherTableau(adresse);
    uneAdresse.ObtenirMasque(masque); // appel d'une méthode
    cout << "Masque : ";
    AfficherTableau(masque);
    uneAdresse.ObtenirAdresseReseau(reseau);
    cout << "Réseau : ";
    AfficherTableau(reseau);
    uneAdresse.ObtenirAdresseDiffusion(diffusion);
    cout << "Diffusion : ";
    AfficherTableau(diffusion);
    uneAdresse.ObtenirPremiereAdresse(premiereAdresse);
    cout << "Première adresse : ";
    AfficherTableau(premiereAdresse);
    uneAdresse.ObtenirDerniereAdresse(derniereAdresse);
    cout << "Dernière adresse : ";
    AfficherTableau(derniereAdresse);

    cout << "Nombre de machine : " << uneAdresse.ObtenirNombreMachines() << endl;

    uneAutreAdresse.ObtenirAdresseReseau(AdresseParDefault);
    cout << "Adresse par défaut : ";
    AfficherTableau(AdresseParDefault);

    AdresseCopie.ObtenirAdresseReseau(AdresseReseauCopie);
    cout << "Adresse réseau de l'adresse copiée : ";
    AfficherTableau(AdresseReseauCopie);

    Adresse3.ObtenirAdresseReseau(reseau);
    cout << "Adresse réseau du réseau 3 : ";
    AfficherTableau(reseau);
    return 0;
}
