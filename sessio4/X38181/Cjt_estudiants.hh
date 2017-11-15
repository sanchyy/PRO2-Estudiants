#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#include "PRO2Excepcio.hh"
#include <vector>
using namespace std;


class Cjt_estudiants {

private:

  // Tipus de modul: dades 

  // Descripció del tipus: representa un conjunt ordenat per DNI
  // d'estudiants. Es poden consultar els seus elements (de tipus
  // Estudiant) donat un DNI o per posició en l'ordre
    
  vector<Estudiant> vest;

  int nest;

  int n_admes;

  int i_min_admes;

  static const int MAX_NEST = 20;

  static const int MAX_PLA = 5;

  /*
    nest és el nombre d'estudiants del p.i.
       
    n_admes és el nombre d'estudiants admesos al curs de reavaluació

    MAX_NEST és la capacitat del p.i.
    
    MAX_PLA és el nombre de places disponibles per al curs de reavaluació    

    Un estudiant "pot optar al curs de reavaluació" si té nota i la
    seva nota és major o igual a 4 i menor que 5. Les places del curs
    de reavaluació s'assignen per ordre descendent de nota entre els
    estudiants que poden optar al curs de reavaluació, i en cas
    d'empat per ordre descendent de DNI. Això significa que, donats
    dos estudiants e1 i e2 que poden optar al curs de reavaluació, e1
    tindria preferència sobre e2 per fer estar admès al curs de reavaluació 
    si e1 té millor nota que e2, o si e1 i e2 tenen la mateixa nota i 
    el DNI d'e1 és més gran que el DNI d'e2.

    i_min_admes és la posició a vest de l'estudiant admès al curs de 
    reavaluació amb menor preferència. Si hi ha estudiants admesos al 
    curs de reavaluació, llavors el valor de l'atribut i_min_admes està 
    dins del interval 0 <= i_min_admes < nest, i i_min_admes conté la 
    posició a vest[0...nest-1] de l'estudiant admès al curs de reavaluació 
    amb nota més petita, i en cas d'empat amb nota i DNI més petits; en cas 
    contrari, si no hi ha estudiants admesos al curs de reavaluació al p.i., 
    llavors i_min_admes és igual a -1.


    Invariant de la representacio:
    I) vest[0..nest-1] està ordenat creixentment per DNI i no conté 
       dos estudiants amb el mateix DNI 
    II) 0 <= nest <= vest.size() = MAX_NEST
    III) MAX_PLA <= MAX_NEST 
    IV) n_admes és el nombre d'estudiants admesos al curs de reavaluació 
        del conjunt i 0 <= n_admes <= MAX_PLA 
    V) si el nombre d'estudiants a vest[0...nest-1] que compleixen les 
       condicions per optar al curs de reavaluació és nc, llavors 
       n_admes = minim(nc, MAX_PLA)
    VI) si no hi ha estudiants admesos al curs de reavaluació a 
        vest[0...nest-1], llavors i_min_admes = -1; en cas contrari, 
        0 <= i_min_admes < nest, vest[i_min_admes] compleix les condicions 
        per optar al curs de reavaluació i està admès al curs de re-avaluació. 

  */

  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: els elements rellevants del paràmetre implícit estan ordenats
     creixentment pels seus DNI */
    
  static int cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x);
  /* Pre: vest.size() > 0, vest[left...right] està ordenat
     creixentment per DNI, 0 <= left <= vest.size(), -1 <= right <
     vest.size(), left <= right + 1 */
  /* Post: si a vest[left ... right] hi ha un estudiant amb DNI = x, el 
     resultat és la posició que hi ocupa; si no, el resultat és la posició 
     que hauria d'ocupar */

  void recalcular_pos_min_admes();
  /* Pre: cert */
  /* Post: Si hi ha estudiants admesos al curs de reavaluació al
    conjunt paràmetre implícit, llavors l'atribut i_min_admes conté
    la posició a vest[0...nest-1] de l'estudiant admès al curs de
    reavaluació amb nota més petita, i en cas d'empat amb nota i DNI
    més petits; si no hi ha estudiants admesos al curs de reavaluació
    al p.i., l'atribut i_min_admes és igual a -1. */


public:

  //Constructors

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadors

  void afegir_estudiant(const Estudiant& est, bool& trobat);
  /* Pre: El nombre d'estudiants del paràmetre impícit es més petit
     que la mida màxima permesa. */
  /* Post: Si el p.i. original no contenia cap estudiant amb el DNI
     d'est, trobat és false, s'ha afegit l'estudiant est al p.i.,
     s'han actualitzat els estudiants admesos al curs de reavaluació
     al p.i. si ha estat necessari, i s'ha actualitzat la posició de
     l'estudiant admès al curs de reavaluació amb nota més petita, i
     en cas d'empat amb nota i DNI més petits, si ha estat necessari. 
     En cas contrari, trobat és true i el p.i. és igual a l'original. */



 // Consultors
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants del paràmetre implícit */

  int n_admesos() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants admesos al curs de
     reavaluació del paràmetre implícit */
    
  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre màxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */

  static int places_disp();
  /* Pre: cert */
  /* Post: el resultat és el nombre de places disponibles per al curs
     de reavaluació */

  int pos_min_admes() const; 
  /* Pre: cert */
  /* Post: Si hi ha estudiants admesos al curs de reavaluació, llavors
  el resultat és la posició "pos" (amb 1 <= pos <= nest) de
  l'estudiant admès al curs de reavaluació amb nota més petita, i en
  cas d'empat amb nota i DNI més petits; si no hi ha estudiants
  admesos al curso de reavaluación al p.i., el resultat és -1. */
        
  void consultar_estudiant(int dni, bool& trobat, Estudiant& e) const;
  /* Pre: cert */
  /* Post: si existeix un estudiant al paràmetre implícit amb DNI =
     dni, trobat és true i "e" és aquest estudiant; altrament trobat és
     false */
    
  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conté el paràmetre implícit */
  /* Post: el resultat és l'estudiant i-essim del paràmetre implícit
     en ordre creixent per DNI */
    
  // Lectura i escriptura
	
    
  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndard de sortida els estudiants del
     paràmetre implicit en ordre ascendent per DNI */
};
#endif
