////**********************************************************************
////**********************************************************************
////
////  RANDOM FORESTS FOR SURVIVAL, REGRESSION, AND CLASSIFICATION (RF-SRC)
////  Version 1.0.0
////
////  Copyright 2012, University of Miami
////
////  This program is free software; you can redistribute it and/or
////  modify it under the terms of the GNU General Public License
////  as published by the Free Software Foundation; either version 2
////  of the License, or (at your option) any later version.
////
////  This program is distributed in the hope that it will be useful,
////  but WITHOUT ANY WARRANTY; without even the implied warranty of
////  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
////  GNU General Public License for more details.
////
////  You should have received a copy of the GNU General Public
////  License along with this program; if not, write to the Free
////  Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
////  Boston, MA  02110-1301, USA.
////
////  ----------------------------------------------------------------
////  Project Partially Funded By: 
////  ----------------------------------------------------------------
////  Dr. Ishwaran's work was funded in part by DMS grant 1148991 from the
////  National Science Foundation and grant R01 CA163739 from the National
////  Cancer Institute.
////
////  Dr. Kogalur's work was funded in part by grant R01 CA163739 from the 
////  National Cancer Institute.
////  ----------------------------------------------------------------
////  Written by:
////  ----------------------------------------------------------------
////    Hemant Ishwaran, Ph.D.
////    Director of Statistical Methodology
////    Professor, Division of Biostatistics
////    Clinical Research Building, Room 1058
////    1120 NW 14th Street
////    University of Miami, Miami FL 33136
////
////    email:  hemant.ishwaran@gmail.com
////    URL:    http://web.ccs.miami.edu/~hishwaran
////    --------------------------------------------------------------
////    Udaya B. Kogalur, Ph.D.
////    Adjunct Staff
////    Dept of Quantitative Health Sciences
////    Cleveland Clinic Foundation
////    
////    Kogalur & Company, Inc.
////    5425 Nestleway Drive, Suite L1
////    Clemmons, NC 27012
////
////    email:  kogalurshear@gmail.com
////    URL:    http://www.kogalur-shear.com
////    --------------------------------------------------------------
////
////**********************************************************************
////**********************************************************************


#ifndef RSFIMPORTANCE_H
#define RSFIMPORTANCE_H
#include "node.h"
Node *getProxyMember(Node    *parent,
                     double **predictor,
                     uint     index);
Node *randomizeMembership(uint     treeID,
                          Node    *parent, 
                          double **predictor, 
                          uint     individual, 
                          uint     splitParameter);
void permute(uint treeID, uint n, uint *indx);
void getRandomMembership(uint      mode,
                         uint      treeID,
                         Node   ***vimpMembership);
void getPermuteMembership(uint      mode,
                          uint      treeID,
                          Node   ***vimpMembership);
void getVIMPmembership(uint      mode, 
                       uint      treeID,
                       Node   ***vimpMembership);
void updateGenericVimpEnsemble (uint       treeID,
                                uint       offset,
                                uint       varLoopCount,
                                uint       obsSize,
                                uint       selectionFlag,
                                uint      *membershipFlag,
                                Node    ***noiseMembership,
                                char       ensembleFlag,
                                double   **outcome,
                                double ****crOutcome,
                                double  ***mcOutcome);
void updateTreeEnsemble (uint       mode,
                         uint       treeID,
                         double   **outcome,
                         double ****crOutcome,
                         double  ***mcOutcome);
void updateVimpEnsemble (uint       mode,
                         uint       treeID,
                         Node    ***vimpMembership);
void summarizeVimpPerformance(uint       mode,
                           uint       treeID);
void finalizeVimpPerformance(uint mode, uint rejectedTreeCount);
Node  ***stackVimpMembership(uint mode);
void     unstackVimpMembership(uint mode, Node ***membership);
void stackTreeEnsemble(uint        mode,
                      double    ***treeOutcome,
                      double  *****crTreeOutcome,
                      double   ****mcTreeOutcome);
void unstackTreeEnsemble(uint       mode,
                        double    **treeOutcome,
                        double  ****crTreeOutcome,
                        double   ***mcTreeOutcome);
#endif
