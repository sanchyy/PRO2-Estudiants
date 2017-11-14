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
  
  int n_bec;
  
  int i_max_no_becat;
  
  static const int MAX_NEST = 20;

  static const int MAX_BEC = 5;

/* 
  nest és el nombre d'estudiants del p.i.

  n_bec és el nombre de beques assignades o equivalentment d'estudiants becats del p.i. 

  MAX_NEST és la capacitat del p.i.

  MAX_BEC és el nombre de beques disponibles

  Un estudiant és "candidat" a obtenir una beca si està aprovat. 
  Donats dos candidats e1 i e2 direm que e1 és millor que e2 si 
  e1 té millor nota que e2, o si e1 i e2 tenen la mateixa nota 
  i el DNI d'e1 és més gran que el DNI d'e2.

  i_max_no_becat és la posició a vest del millor candidat no becat 
  del paràmetre implícit. Si hi ha candidats sense beca al p.i., 
  llavors i_max_no_becat conté la posició a vest[0...nest-1] del 
  millor candidat no becat i el seu valor està dins del interval 
  0 <= i_max_no_becat < nest; si no hi ha candidats sense beca al 
  p.i., llavors i_max_no_becat = -1.
 

    Invariant de la representació:
    I) vest[0..nest-1] està ordenat creixentment per DNI i no conté 
       dos estudiants amb el mateix DNI 
    II) 0 <= nest <= vest.size() = MAX_NEST
    III) MAX_BEC <= MAX_NEST
    IV) n_bec és el nombre d'estudiants amb beca del conjunt i 
        0 <= n_bec <= MAX_BEC 
    V) si el nombre d'estudiants aprovats a vest[0...nest-1] és na, 
       n_bec = mínim(na, MAX_BEC);  
    VI) si no hi ha candidats sense beca a vest[0...nest-1], i_max_no_becat = -1; 
        en cas contrari, 0 <= i_max_no_becat < nest, vest[i_max_no_becat] està 
        aprovat i no té beca, i hi ha n_bec estudiants amb beca a vest[0...nest-1] 
        que tenen millor nota que vest[i_max_no_becat], o la mateixa nota i DNI més 
        gran que vest[i_max_no_becat].   
  */

  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: els elements rellevants del paràmetre implícit estan ordenats
     creixentment pels seus DNI */
    
  static int cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x);
  /* Pre: vest.size() > 0, vest[left...right] està ordenat
     creixentment per DNI, 0 <= left <= vest.size(), -1 <= right < vest.size(), 
     left <= right + 1 */
  /* Post: si a vest[left ... right] hi ha un estudiant amb DNI = x, el 
     resultat és la posició que hi ocupa; si no, el resultat és la posició  
     que hauria d'ocupar */

  void recalcular_pos_max_no_becat();
  /* Pre: cert */
  /* Post: Si hi ha candidats sense beca al conjunt paràmetre
  implícit, l'atribut i_max_no_becat conté la posicio del millor
  candidat no becat i el seu valor esta dins de l'interval 
  0 <= i_max_no_becat < nest; si no hi ha candidats sense beca 
  al p.i., llavors l'atribut i_max_no_becat = -1. */


public:

  //Constructors

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadors
    
  void esborrar_estudiant(int x, bool& trobat);
  /* Pre: cert  */
  /* Post: Si el paràmetre implícit original contenia un estudiant amb
     DNI = x, trobat és true, el p.i. conté els mateixos estudiants
     que l'original menys l'estudiant amb DNI = x, s'han actualizat
     els estudiants becats del p.i. si ha estat necessari, i s'ha 
     actualitzat la posició del millor candidat no becat si ha estat 
     necessari; 
     altrament, trobat és false i el p.i. és igual a l'original. */

  
    //Consultors
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants del paràmetre implícit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre màxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */

  int b_assignades() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants amb beca del paràmetre implícit */
    
  static int bec_disp();
  /* Pre: cert */
  /* Post: el resultat és el nombre de becas disponibles */
        
  int pos_max_no_becat() const;
  /* Pre: cert */
  /* Post: Si hi ha candidats sense beca al conjunt paràmetre
  implícit, llavors el resultat és la posició "pos" del millor
  candidat no becat, on 1 <= pos <= nest; 
  si no hi ha candidats sense beca al p.i., el resultat és -1 */ 

  void consultar_estudiant(int dni, bool& trobat, Estudiant& e) const;
  /* Pre: cert */
  /* Post: si existeix un estudiant al paràmetre implícit amb DNI=dni, 
     trobat és true i "e" és aquest estudiant; altrament trobat és
     false */
    
  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conté el paràmetre implícit */
  /* Post: el resultat és l'estudiant i-essim del paràmetre implícit
     en ordre creixent per DNI */
    
  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal estàndard d'entrada un enter entre 
     0 i la mida màxima permesa, que representa el nombre d'elements
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndard d'entrada */
    
  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndard de sortida els estudiants del
     paràmetre implícit en ordre ascendent per DNI */
};
#endif

