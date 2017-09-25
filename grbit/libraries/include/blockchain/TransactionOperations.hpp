#pragma once

#include <blockchain/TransactionEntry.hpp>
#include <blockchain/Operations.hpp>

namespace TiValue {
    namespace blockchain {

        struct TransactionOperation
        {
            static const OperationTypeEnum type;

            TransactionOperation(){}

            TransactionOperation(const SignedTransaction& signed_trx)
                :trx(signed_trx){}

            TransactionOperation(const TransactionOperation& trx_op)
                :trx(trx_op.trx){}

            SignedTransaction trx;

            void evaluate(TransactionEvaluationState& eval_state)const;
        };

    }
} // TiValue::blockchain


FC_REFLECT(TiValue::blockchain::TransactionOperation, (trx))
