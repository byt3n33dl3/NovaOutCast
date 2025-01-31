//
// Created by vladimir on 16.10.19.
//

#ifndef NOVAOUTCAST_CONSUMER_H
#define NOVAOUTCAST_CONSUMER_H

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "MatchHandler.h"

namespace AVObfuscator   {
    extern clang::Rewriter ASTRewriter;
}

class Consumer : public clang::ASTConsumer {
public:

    void HandleTranslationUnit(clang::ASTContext &Context) override {

        for(auto consumer: consumers)   {
            llvm::outs() << "Running new consumer...\n";
            consumer->HandleTranslationUnit(Context);
        }
    }

    std::vector<ASTConsumer*> consumers;
};

#endif //NOVAOUTCAST_CONSUMER_H
