//
// Created by sebas on 9/9/19.
//

#include "gtest/gtest.h"
#include "../servicios/Logger.h"
#include "gmock/gmock.h"

TEST(Logger, LoggerFuncionaBienParaNivelesMenores) {
    testing::internal::CaptureStdout();

    auto *logger = new Logger("INFO");
    logger->log(ERROR, "Un errror ocurrió");

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_THAT(output, testing:: HasSubstr("Un errror ocurrió"));
}

TEST(Logger, LoggerFuncionaBienParaNivelesIguales) {
    testing::internal::CaptureStdout();

    Logger logger("INFO");
    logger.log(INFO, "Log de info");

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_THAT(output, testing:: HasSubstr("Log de info"));
}

TEST(Logger, LoggerNoMuestraNadaParaNivelesMayores) {
    testing::internal::CaptureStdout();

    Logger logger("INFO");
    logger.log(DEBUG, "Log de bug");

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_THAT(output, "");
}