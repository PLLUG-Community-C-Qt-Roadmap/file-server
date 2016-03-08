#ifndef HTMLCONTENTGENERATOR
#define HTMLCONTENTGENERATOR
#include "configurable.h"
#include "generator.h"
#include <iostream>
#include <mstch/mstch.hpp>

using namespace std;
class HTMLContentGenerator: public Configurable, public Generator
{

public:
     HTMLContentGenerator(Configuration& gen):Configurable(mConfigObj){}


     string generate()
     {
         std::string view{"{{#names}}Hi {{name}}!\n{{/names}}"};
         mstch::map context{
           {"names", mstch::array{
             mstch::map{{"name", std::string{"Roma"}}},
             mstch::map{{"name", std::string{"Maks"}}},
             mstch::map{{"name", std::string{"Yura"}}},
           }}
         };

         return mstch::render(view, context);

     }

};



#endif // HTMLCONTENTGENERATOR

