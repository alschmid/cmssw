
//
// F.Ratnikov (UMd), Aug. 9, 2005
//

#ifndef HcalDbService_h
#define HcalDbService_h

#include <memory>
#include <map>

#include "DataFormats/HcalDetId/interface/HcalGenericDetId.h"
#include "CalibFormats/HcalObjects/interface/HcalChannelCoder.h"
#include "CalibFormats/HcalObjects/interface/QieShape.h"
#include "CalibFormats/HcalObjects/interface/HcalCoder.h"
#include "CalibFormats/HcalObjects/interface/HcalCalibrationsSet.h"
#include "CalibFormats/HcalObjects/interface/HcalCalibrationWidthsSet.h"

#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/Framework/interface/ESProducer.h"

#include "CondFormats/HcalObjects/interface/AllObjects.h"

class HcalCalibrations;
class HcalCalibrationWidths;
class HcalTopology;

class HcalDbService {
 public:
  HcalDbService (const edm::ParameterSet&);

  const HcalTopology* getTopologyUsed() const;
  
  const HcalCalibrations& getHcalCalibrations(const HcalGenericDetId& fId) const;
    const HcalCalibrationWidths& getHcalCalibrationWidths(const HcalGenericDetId& fId) const;

  const HcalPedestal* getPedestal (const HcalGenericDetId& fId) const;
  const HcalPedestalWidth* getPedestalWidth (const HcalGenericDetId& fId) const;
  const HcalGain* getGain (const HcalGenericDetId& fId) const;
  const HcalGainWidth* getGainWidth (const HcalGenericDetId& fId) const;
  const HcalQIECoder* getHcalCoder (const HcalGenericDetId& fId) const;
  const HcalQIEShape* getHcalShape (const HcalGenericDetId& fId) const;
  const HcalQIEShape* getHcalShape (const HcalQIECoder *coder) const;
  const HcalElectronicsMap* getHcalMapping () const;
  const HcalRespCorr* getHcalRespCorr (const HcalGenericDetId& fId) const;
  const HcalTimeCorr* getHcalTimeCorr (const HcalGenericDetId& fId) const;
  const HcalL1TriggerObject* getHcalL1TriggerObject (const HcalGenericDetId& fId) const;
  const HcalChannelStatus* getHcalChannelStatus (const HcalGenericDetId& fId) const;
  const HcalZSThreshold* getHcalZSThreshold (const HcalGenericDetId& fId) const;
  const HcalLUTCorr* getHcalLUTCorr (const HcalGenericDetId& fId) const;
  const HcalPFCorr* getHcalPFCorr (const HcalGenericDetId& fId) const;
  const HcalLutMetadata* getHcalLutMetadata () const;

  void setData (const HcalPedestals* fItem) {mPedestals = fItem; mUpdateCalibrations = true; }
  void setData (const HcalPedestalWidths* fItem) {mPedestalWidths = fItem; mUpdateCalibWidths = true; }
  void setData (const HcalGains* fItem) {mGains = fItem; mUpdateCalibrations = true; }
  void setData (const HcalGainWidths* fItem) {mGainWidths = fItem; mUpdateCalibWidths = true; }
  void setData (const HcalQIEData* fItem) {mQIEData = fItem; mUpdateCalibrations = true; mUpdateCalibWidths = true; }
  void setData (const HcalChannelQuality* fItem) {mChannelQuality = fItem;}
  void setData (const HcalElectronicsMap* fItem) {mElectronicsMap = fItem;}
  void setData (const HcalRespCorrs* fItem) {mRespCorrs = fItem; mUpdateCalibrations = true; }
  void setData (const HcalTimeCorrs* fItem) {mTimeCorrs = fItem; mUpdateCalibrations = true; }
  void setData (const HcalZSThresholds* fItem) {mZSThresholds = fItem;}
  void setData (const HcalL1TriggerObjects* fItem) {mL1TriggerObjects = fItem;}
  void setData (const HcalLUTCorrs* fItem) {mLUTCorrs = fItem; mUpdateCalibrations = true; }
  void setData (const HcalPFCorrs* fItem) {mPFCorrs = fItem; }
  void setData (const HcalLutMetadata* fItem) {mLutMetadata = fItem;}

 private:
  bool makeHcalCalibration (const HcalGenericDetId& fId, HcalCalibrations* fObject, 
			    bool pedestalInADC) const;
  void buildCalibrations() const;
  bool makeHcalCalibrationWidth (const HcalGenericDetId& fId, HcalCalibrationWidths* fObject, 
				 bool pedestalInADC) const;
  void buildCalibWidths() const;
  const HcalPedestals* mPedestals;
  const HcalPedestalWidths* mPedestalWidths;
  const HcalGains* mGains;
  const HcalGainWidths* mGainWidths;
  mutable HcalQIEShape* mQieShapeCache;
  const HcalQIEData* mQIEData;
  const HcalChannelQuality* mChannelQuality;
  const HcalElectronicsMap* mElectronicsMap;
  const HcalRespCorrs* mRespCorrs;
  const HcalZSThresholds* mZSThresholds;
  const HcalL1TriggerObjects* mL1TriggerObjects;
  const HcalTimeCorrs* mTimeCorrs;
  const HcalLUTCorrs* mLUTCorrs;
  const HcalPFCorrs* mPFCorrs;
  const HcalLutMetadata* mLutMetadata;
  //  bool mPedestalInADC;
  mutable HcalCalibrationsSet mCalibSet;
  mutable HcalCalibrationWidthsSet mCalibWidthSet;
  mutable bool mUpdateCalibrations, mUpdateCalibWidths;
};

#endif
