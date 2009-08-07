// ============================================================================
// Copyright Jean-Charles LAMBERT - 2007-2009                                  
// e-mail:   Jean-Charles.Lambert@oamp.fr                                      
// address:  Dynamique des galaxies                                            
//           Laboratoire d'Astrophysique de Marseille                          
//           P�le de l'Etoile, site de Ch�teau-Gombert                         
//           38, rue Fr�d�ric Joliot-Curie                                     
//           13388 Marseille cedex 13 France                                   
//           CNRS U.M.R 6110                                                   
// ============================================================================
// See the complete license in LICENSE and/or "http://www.cecill.info".        
// ============================================================================
#include "globject.h"

#define LOCAL_DEBUG 0
//#include "print_debug.h"

namespace glnemo {


// ============================================================================
// Constructor                                                                 
GLObject::GLObject()
{
  is_activated=TRUE;
  this->setColor(Qt::yellow);
  particles_alpha=255;
}
// ============================================================================
// Destructor                                                                  
GLObject::~GLObject()
{
} 
// ============================================================================
// GLObject::display()                                                         
// Display object, via display list, if activated                              
void GLObject::display(int my_list)
{
  if (is_activated) {
    if (my_list == -1) my_list=dplist_index;
    glColor4ub(mycolor.red(), mycolor.green(), mycolor.blue(),particles_alpha);
    glCallList((GLuint) my_list);
  }
}
// ============================================================================
// GLObject::updateAlphaSlot()                                                 
// update particle alpha color                                                 
void GLObject::updateAlphaSlot(const int _alpha)
{ 
  particles_alpha = _alpha;
}
// ============================================================================
// GLObject::toggleActivate()                                                  
// toggle activate                                                             
void GLObject::toggleActivate()
{
  is_activated = ! is_activated;
}
// ============================================================================
// GLObject::setColor()                                                        
// Set object color                                                            
void GLObject::setColor(const QColor &c)
{
  mycolor = c;
}
// ============================================================================
// GLObject::buildDisplayList()                                                
// Build display list                                                          
void GLObject::buildDisplayList()
{
}
// ============================================================================


}