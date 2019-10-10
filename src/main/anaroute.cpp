/**
 * @file   anaroute.cpp
 * @brief  Analog Router
 * @author Hao Chen
 * @date   09/01/2019
 *
 **/

#include "anaroute.hpp"
#include "src/util/util.hpp"
#include "src/util/timeUsage.hpp"
#include "src/db/dbCir.hpp"
#include "src/parser/parser.hpp"
#include "src/gr/grMgr.hpp"
#include "src/ta/taMgr.hpp"
#include "src/dr/drMgr.hpp"

PROJECT_NAMESPACE_START

Anaroute::Anaroute(int argc, char** argv) {
 
  util::showSysInfo();

  TimeUsage timer;
  timer.start(TimeUsage::FULL);

  parseArgs(argc, argv);
  
  CirDB cir;
  
  // parse files
  timer.start(TimeUsage::PARTIAL);
  Parser par(cir);
  par.parseLef(_args.get<String_t>("tech_lef"));
  par.parseTechfile(_args.get<String_t>("tech_file"));
  par.parseIspd08(_args.get<String_t>("design_file"));
  par.parseGds(_args.get<String_t>("placement_layout"));
  par.parseSymNet(_args.get<String_t>("symnet"));
  //cir.printInfo();
  cir.buildSpatial();
  timer.showUsage("Circuit database construction", TimeUsage::PARTIAL);
  
  // global routing
  timer.start(TimeUsage::PARTIAL);
  GrMgr gr(cir);
  gr.solve();
  timer.showUsage("Global Routing", TimeUsage::PARTIAL);

  // track assignment
  TaMgr ta(cir);
  ta.solve();

  // detailed routing
  DrMgr dr(cir);
  dr.solve();

  timer.showUsage("Anaroute", TimeUsage::FULL);
  printf("Peak Memory Usage: %.2f MB\n", util::getPeakMemoryUsage() / MEM_SCALE);
}

void Anaroute::parseArgs(int argc, char** argv) {
  _args.add<String_t>("tech_lef", '\0', "technology lef file");
  _args.add<String_t>("tech_file", '\0', "technology layer file");
  _args.add<String_t>("design_type", '\0', "design type");
  _args.add<String_t>("design_file", '\0', "design file");
  _args.add<String_t>("placement_layout", '\0', "placement layout file");
  _args.add<String_t>("iopin", '\0', "IO-Pin file");
  _args.add<String_t>("symnet", '\0', "symmetric nets file");
  _args.add<String_t>("out", 'o', "output file");
  _args.parse_check(argc, argv);
}


PROJECT_NAMESPACE_END


