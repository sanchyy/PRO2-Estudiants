#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#include "PRO2Excepcio.hh"
#include <vector>
using namespace std;


class Cjt_estudiants {

private:

  // Tipus de modul: dades 

  // Descripci� del tipus: representa un conjunt ordenat per DNI
  // d'estudiants. Es poden consultar els seus elements (de tipus
  // Estudiant) donat un DNI o per posici� en l'ordre
    
  vector<Estudiant> vest;

  int nest;

  int n_admes;

  int i_min_admes;

  static const int MAX_NEST = 20;

  static const int MAX_PLA = 5;

  /*
    nest �s el nombre d'estudiants del p.i.
       
    n_admes �s el nombre d'estudiants admesos al curs de reavaluaci�

    MAX_NEST �s la capacitat del p.i.
    
    MAX_PLA �s el nombre de places disponibles per al curs de reavaluaci�    

    Un estudiant "pot optar al curs de reavaluaci�" si t� nota i la
    seva nota �s major o igual a 4 i menor que 5. Les places del curs
    de reavaluaci� s'assignen per ordre descendent de nota entre els
    estudiants que poden optar al curs de reavaluaci�, i en cas
    d'empat per ordre descendent de DNI. Aix� significa que, donats
    dos estudiants e1 i e2 que poden optar al curs de reavaluaci�, e1
    tindria prefer�ncia sobre e2 per fer estar adm�s al curs de reavaluaci� 
    si e1 t� millor nota que e2, o si e1 i e2 tenen la mateixa nota i 
    el DNI d'e1 �s m�s gran que el DNI d'e2.

    i_min_admes �s la posici� a vest de l'estudiant adm�s al curs de 
    reavaluaci� amb menor prefer�ncia. Si hi ha estudiants admesos al 
    curs de reavaluaci�, llavors el valor de l'atribut i_min_admes est� 
    dins del interval 0 <= i_min_admes < nest, i i_min_admes cont� la 
    posici� a vest[0...nest-1] de l'estudiant adm�s al curs de reavaluaci� 
    amb nota m�s petita, i en cas d'empat amb nota i DNI m�s petits; en cas 
    contrari, si no hi ha estudiants admesos al curs de reavaluaci� al p.i., 
    llavors i_min_admes �s igual a -1.


    Invariant de la representacio:
    I) vest[0..nest-1] est� ordenat creixentment per DNI i no cont� 
       dos estudiants amb el mateix DNI 
    II) 0 <= nest <= vest.size() = MAX_NEST
    III) MAX_PLA <= MAX_NEST 
    IV) n_admes �s el nombre d'estudiants admesos al curs de reavaluaci� 
        del conjunt i 0 <= n_admes <= MAX_PLA 
    V) si el nombre d'estudiants a vest[0...nest-1] que compleixen les 
       condicions per optar al curs de reavaluaci� �s nc, llavors 
       n_admes = minim(nc, MAX_PLA)
    VI) si no hi ha estudiants admesos al curs de reavaluaci� a 
        vest[0...nest-1], llavors i_min_admes = -1; en cas contrari, 
        0 <= i_min_admes < nest, vest[i_min_admes] compleix les condicions 
        per optar al curs de reavaluaci� i est� adm�s al curs de re-avaluaci�. 

  */

  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: els elements rellevants del par�metre impl�cit estan ordenats
     creixentment pels seus DNI */
    
  static int cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x);
  /* Pre: vest.size() > 0, vest[left...right] est� ordenat
     creixentment per DNI, 0 <= left <= vest.size(), -1 <= right <
     vest.size(), left <= right + 1 */
  /* Post: si a vest[left ... right] hi ha un estudiant amb DNI = x, el 
     resultat �s la posici� que hi ocupa; si no, el resultat �s la posici� 
     que hauria d'ocupar */

  void recalcular_pos_min_admes();
  /* Pre: cert */
  /* Post: Si hi ha estudiants admesos al curs de reavaluaci� al
    conjunt par�metre impl�cit, llavors l'atribut i_min_admes cont�
    la posici� a vest[0...nest-1] de l'estudiant adm�s al curs de
    reavaluaci� amb nota m�s petita, i en cas d'empat amb nota i DNI
    m�s petits; si no hi ha estudiants admesos al curs de reavaluaci�
    al p.i., l'atribut i_min_admes �s igual a -1. */


public:

  //Constructors

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadors

  void afegir_estudiant(const Estudiant& est, bool& trobat);
  /* Pre: El nombre d'estudiants del par�metre imp�cit es m�s petit
     que la mida m�xima permesa. */
  /* Post: Si el p.i. original no contenia cap estudiant amb el DNI
     d'est, trobat �s false, s'ha afegit l'estudiant est al p.i.,
     s'han actualitzat els estudiants admesos al curs de reavaluaci�
     al p.i. si ha estat necessari, i s'ha actualitzat la posici� de
     l'estudiant adm�s al curs de reavaluaci� amb nota m�s petita, i
     en cas d'empat amb nota i DNI m�s petits, si ha estat necessari. 
     En cas contrari, trobat �s true i el p.i. �s igual a l'original. */



 // Consultors
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat �s el nombre d'estudiants del par�metre impl�cit */

  int n_admesos() const;
  /* Pre: cert */
  /* Post: el resultat �s el nombre d'estudiants admesos al curs de
     reavaluaci� del par�metre impl�cit */
    
  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat �s el nombre m�xim d'estudiants que pot arribar
     a tenir el par�metre impl�cit */

  static int places_disp();
  /* Pre: cert */
  /* Post: el resultat �s el nombre de places disponibles per al curs
     de reavaluaci� */

  int pos_min_admes() const; 
  /* Pre: cert */
  /* Post: Si hi ha estudiants admesos al curs de reavaluaci�, llavors
  el resultat �s la posici� "pos" (amb 1 <= pos <= nest) de
  l'estudiant adm�s al curs de reavaluaci� amb nota m�s petita, i en
  cas d'empat amb nota i DNI m�s petits; si no hi ha estudiants
  admesos al curso de reavaluaci�n al p.i., el resultat �s -1. */
        
  void consultar_estudiant(int dni, bool& trobat, Estudiant& e) const;
  /* Pre: cert */
  /* Post: si existeix un estudiant al par�metre impl�cit amb DNI =
     dni, trobat �s true i "e" �s aquest estudiant; altrament trobat �s
     false */
    
  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que cont� el par�metre impl�cit */
  /* Post: el resultat �s l'estudiant i-essim del par�metre impl�cit
     en ordre creixent per DNI */
    
  // Lectura i escriptura
	
    
  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndard de sortida els estudiants del
     par�metre implicit en ordre ascendent per DNI */
};
#endif
