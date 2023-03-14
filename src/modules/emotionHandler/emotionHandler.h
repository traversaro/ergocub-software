/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

#ifndef __EMOTIONHANDLER__
#define __EMOTIONHANDLER__

#include <yarp/os/Vocab.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/ResourceFinder.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/RpcServer.h>
#include <yarp/os/BufferedPort.h>

// define the vocabs
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_SET = yarp::os::createVocab32('s','e','t');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_GET = yarp::os::createVocab32('g','e','t');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_IS  = yarp::os::createVocab32('i','s');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_FAILED = yarp::os::createVocab32('f','a','i','l');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_OK = yarp::os::createVocab32('o','k');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_HELP = yarp::os::createVocab32('h','e','l','p');

constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_NEUTRAL = yarp::os::createVocab32('n','e','u');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_HAPPY = yarp::os::createVocab32('h','a','p');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_SAD = yarp::os::createVocab32('s','a','d');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_SURPRISED = yarp::os::createVocab32('s','u','r');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_ANGRY = yarp::os::createVocab32('a','n','g');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_EVIL = yarp::os::createVocab32('e','v','i');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_SHY = yarp::os::createVocab32('s','h','y');
constexpr  yarp::conf::vocab32_t EMOTION_VOCAB_CUN = yarp::os::createVocab32('c','u','n');

// EmotionHandler class definition
class EmotionHandler : public yarp::os::RFModule {
    private:
        
    public:
        EmotionHandler();
        ~EmotionHandler();
        
        bool configure(yarp::os::ResourceFinder& config);
        bool close();
        bool updateModule();
        bool respond(const yarp::os::Bottle &cmd, yarp::os::Bottle &reply);
        double getPeriod();

        bool getCommand(const std::string command);

        yarp::os::RpcServer rpcPort;
};

#endif