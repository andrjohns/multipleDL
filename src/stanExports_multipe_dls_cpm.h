// Generated by rstantools.  Do not edit by hand.

/*
    multipledls is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    multipledls is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with multipledls.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1
#include <stan/model/model_header.hpp>
namespace model_multipe_dls_cpm_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_multipe_dls_cpm");
    reader.add_event(68, 66, "end", "model_multipe_dls_cpm");
    return reader;
}
template <typename T0__>
typename boost::math::tools::promote_args<T0__>::type
func_link(const T0__& x,
              const int& link_num, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        current_statement_begin__ = 3;
        if (as_bool(logical_eq(link_num, 1))) {
            current_statement_begin__ = 3;
            return stan::math::promote_scalar<fun_return_scalar_t__>(inv_logit(x));
        } else if (as_bool(logical_eq(link_num, 2))) {
            current_statement_begin__ = 4;
            return stan::math::promote_scalar<fun_return_scalar_t__>(Phi(x));
        } else if (as_bool(logical_eq(link_num, 3))) {
            current_statement_begin__ = 5;
            return stan::math::promote_scalar<fun_return_scalar_t__>(gumbel_cdf(x, 0, 1));
        } else if (as_bool(logical_eq(link_num, 4))) {
            current_statement_begin__ = 6;
            return stan::math::promote_scalar<fun_return_scalar_t__>(inv_cloglog(x));
        } else {
            current_statement_begin__ = 7;
            return stan::math::promote_scalar<fun_return_scalar_t__>(x);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
struct func_link_functor__ {
    template <typename T0__>
        typename boost::math::tools::promote_args<T0__>::type
    operator()(const T0__& x,
              const int& link_num, std::ostream* pstream__) const {
        return func_link(x, link_num, pstream__);
    }
};
template <typename T0__, typename T1__, typename T3__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T3__>::type, Eigen::Dynamic, 1>
loglik(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& alpha,
           const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& beta,
           const std::vector<int>& delta,
           const std::vector<Eigen::Matrix<T3__, 1, Eigen::Dynamic> >& X,
           const std::vector<int>& j,
           const int& link_num, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T3__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 12;
        int N(0);
        (void) N;  // dummy to suppress unused var warning
        stan::math::fill(N, std::numeric_limits<int>::min());
        stan::math::assign(N,size(X));
        current_statement_begin__ = 13;
        validate_non_negative_index("out", "N", N);
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> out(N);
        stan::math::initialize(out, DUMMY_VAR__);
        stan::math::fill(out, DUMMY_VAR__);
        current_statement_begin__ = 14;
        int J(0);
        (void) J;  // dummy to suppress unused var warning
        stan::math::fill(J, std::numeric_limits<int>::min());
        stan::math::assign(J,max(j));
        current_statement_begin__ = 15;
        for (int n = 1; n <= N; ++n) {
            {
            current_statement_begin__ = 16;
            local_scalar_t__ eta(DUMMY_VAR__);
            (void) eta;  // dummy to suppress unused var warning
            stan::math::initialize(eta, DUMMY_VAR__);
            stan::math::fill(eta, DUMMY_VAR__);
            stan::math::assign(eta,multiply(get_base1(X, n, "X", 1), beta));
            current_statement_begin__ = 17;
            int j_n(0);
            (void) j_n;  // dummy to suppress unused var warning
            stan::math::fill(j_n, std::numeric_limits<int>::min());
            stan::math::assign(j_n,get_base1(j, n, "j", 1));
            current_statement_begin__ = 18;
            int delta_n(0);
            (void) delta_n;  // dummy to suppress unused var warning
            stan::math::fill(delta_n, std::numeric_limits<int>::min());
            stan::math::assign(delta_n,get_base1(delta, n, "delta", 1));
            current_statement_begin__ = 19;
            if (as_bool(logical_eq(delta_n, 2))) {
                current_statement_begin__ = 19;
                stan::model::assign(out, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            stan::math::log(func_link((get_base1(alpha, j_n, "alpha", 1) - eta), link_num, pstream__)), 
                            "assigning variable out");
            } else if (as_bool(logical_eq(delta_n, 3))) {
                current_statement_begin__ = 20;
                stan::model::assign(out, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            log1m(func_link((get_base1(alpha, (j_n - 1), "alpha", 1) - eta), link_num, pstream__)), 
                            "assigning variable out");
            } else if (as_bool((primitive_value(logical_eq(delta_n, 12)) || primitive_value(logical_eq(j_n, 1))))) {
                current_statement_begin__ = 21;
                stan::model::assign(out, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            stan::math::log(func_link((get_base1(alpha, 1, "alpha", 1) - eta), link_num, pstream__)), 
                            "assigning variable out");
            } else if (as_bool((primitive_value(logical_eq(delta_n, 13)) || primitive_value(logical_eq(j_n, J))))) {
                current_statement_begin__ = 22;
                stan::model::assign(out, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            log1m(func_link((get_base1(alpha, (J - 1), "alpha", 1) - eta), link_num, pstream__)), 
                            "assigning variable out");
            } else {
                current_statement_begin__ = 23;
                stan::model::assign(out, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            stan::math::log((func_link((get_base1(alpha, j_n, "alpha", 1) - eta), link_num, pstream__) - func_link((get_base1(alpha, (j_n - 1), "alpha", 1) - eta), link_num, pstream__))), 
                            "assigning variable out");
            }
            }
        }
        current_statement_begin__ = 25;
        return stan::math::promote_scalar<fun_return_scalar_t__>(out);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
struct loglik_functor__ {
    template <typename T0__, typename T1__, typename T3__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T3__>::type, Eigen::Dynamic, 1>
    operator()(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& alpha,
           const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& beta,
           const std::vector<int>& delta,
           const std::vector<Eigen::Matrix<T3__, 1, Eigen::Dynamic> >& X,
           const std::vector<int>& j,
           const int& link_num, std::ostream* pstream__) const {
        return loglik(alpha, beta, delta, X, j, link_num, pstream__);
    }
};
#include <stan_meta_header.hpp>
class model_multipe_dls_cpm : public prob_grad {
private:
        int N;
        int p;
        std::vector<row_vector_d> X;
        int J;
        std::vector<int> j;
        std::vector<int> delta;
        int link_num;
        double sds;
public:
    model_multipe_dls_cpm(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_multipe_dls_cpm(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_multipe_dls_cpm_namespace::model_multipe_dls_cpm";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 32;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);
            current_statement_begin__ = 33;
            context__.validate_dims("data initialization", "p", "int", context__.to_vec());
            p = int(0);
            vals_i__ = context__.vals_i("p");
            pos__ = 0;
            p = vals_i__[pos__++];
            check_greater_or_equal(function__, "p", p, 1);
            current_statement_begin__ = 34;
            validate_non_negative_index("X", "p", p);
            validate_non_negative_index("X", "N", N);
            context__.validate_dims("data initialization", "X", "row_vector_d", context__.to_vec(N,p));
            X = std::vector<Eigen::Matrix<double, 1, Eigen::Dynamic> >(N, Eigen::Matrix<double, 1, Eigen::Dynamic>(p));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_j_1_max__ = p;
            size_t X_k_0_max__ = N;
            for (size_t j_1__ = 0; j_1__ < X_j_1_max__; ++j_1__) {
                for (size_t k_0__ = 0; k_0__ < X_k_0_max__; ++k_0__) {
                    X[k_0__](j_1__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 35;
            context__.validate_dims("data initialization", "J", "int", context__.to_vec());
            J = int(0);
            vals_i__ = context__.vals_i("J");
            pos__ = 0;
            J = vals_i__[pos__++];
            check_greater_or_equal(function__, "J", J, 2);
            current_statement_begin__ = 36;
            validate_non_negative_index("j", "N", N);
            context__.validate_dims("data initialization", "j", "int", context__.to_vec(N));
            j = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("j");
            pos__ = 0;
            size_t j_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < j_k_0_max__; ++k_0__) {
                j[k_0__] = vals_i__[pos__++];
            }
            size_t j_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < j_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "j[i_0__]", j[i_0__], 1);
                check_less_or_equal(function__, "j[i_0__]", j[i_0__], J);
            }
            current_statement_begin__ = 37;
            validate_non_negative_index("delta", "N", N);
            context__.validate_dims("data initialization", "delta", "int", context__.to_vec(N));
            delta = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("delta");
            pos__ = 0;
            size_t delta_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < delta_k_0_max__; ++k_0__) {
                delta[k_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 38;
            context__.validate_dims("data initialization", "link_num", "int", context__.to_vec());
            link_num = int(0);
            vals_i__ = context__.vals_i("link_num");
            pos__ = 0;
            link_num = vals_i__[pos__++];
            current_statement_begin__ = 41;
            context__.validate_dims("data initialization", "sds", "double", context__.to_vec());
            sds = double(0);
            vals_r__ = context__.vals_r("sds");
            pos__ = 0;
            sds = vals_r__[pos__++];
            check_greater_or_equal(function__, "sds", sds, 0);
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 46;
            validate_non_negative_index("beta", "p", p);
            num_params_r__ += p;
            current_statement_begin__ = 47;
            validate_non_negative_index("pi", "J", J);
            num_params_r__ += (J - 1);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_multipe_dls_cpm() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 46;
        if (!(context__.contains_r("beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        validate_non_negative_index("beta", "p", p);
        context__.validate_dims("parameter initialization", "beta", "vector_d", context__.to_vec(p));
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta(p);
        size_t beta_j_1_max__ = p;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            beta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 47;
        if (!(context__.contains_r("pi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable pi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("pi");
        pos__ = 0U;
        validate_non_negative_index("pi", "J", J);
        context__.validate_dims("parameter initialization", "pi", "vector_d", context__.to_vec(J));
        Eigen::Matrix<double, Eigen::Dynamic, 1> pi(J);
        size_t pi_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            pi(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.simplex_unconstrain(pi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable pi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 46;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> beta;
            (void) beta;  // dummy to suppress unused var warning
            if (jacobian__)
                beta = in__.vector_constrain(p, lp__);
            else
                beta = in__.vector_constrain(p);
            current_statement_begin__ = 47;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> pi;
            (void) pi;  // dummy to suppress unused var warning
            if (jacobian__)
                pi = in__.simplex_constrain(J, lp__);
            else
                pi = in__.simplex_constrain(J);
            // transformed parameters
            current_statement_begin__ = 51;
            validate_non_negative_index("alpha", "(J - 1)", (J - 1));
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> alpha((J - 1));
            stan::math::initialize(alpha, DUMMY_VAR__);
            stan::math::fill(alpha, DUMMY_VAR__);
            current_statement_begin__ = 52;
            validate_non_negative_index("log_lik", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> log_lik(N);
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 54;
            if (as_bool(logical_eq(link_num, 1))) {
                current_statement_begin__ = 54;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 54;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                logit((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi")))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 55;
            if (as_bool(logical_eq(link_num, 2))) {
                current_statement_begin__ = 55;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 55;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                inv_Phi((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi")))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 56;
            if (as_bool(logical_eq(link_num, 3))) {
                current_statement_begin__ = 56;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 56;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                -(stan::math::log(-(stan::math::log((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi"))))))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 57;
            if (as_bool(logical_eq(link_num, 4))) {
                current_statement_begin__ = 57;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 57;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                stan::math::log(-(log1m((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi")))))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 59;
            stan::math::assign(log_lik, loglik(alpha, beta, delta, X, j, link_num, pstream__));
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 51;
            size_t alpha_j_1_max__ = (J - 1);
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(alpha(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: alpha" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable alpha: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 52;
            size_t log_lik_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(log_lik(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: log_lik" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable log_lik: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            current_statement_begin__ = 63;
            lp_accum__.add(log_lik);
            current_statement_begin__ = 64;
            lp_accum__.add(normal_log(beta, 0, rep_vector(sds, p)));
            current_statement_begin__ = 65;
            lp_accum__.add(dirichlet_log(pi, rep_vector(1, J)));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("beta");
        names__.push_back("pi");
        names__.push_back("alpha");
        names__.push_back("log_lik");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(p);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back((J - 1));
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_multipe_dls_cpm_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta = in__.vector_constrain(p);
        size_t beta_j_1_max__ = p;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            vars__.push_back(beta(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> pi = in__.simplex_constrain(J);
        size_t pi_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            vars__.push_back(pi(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 51;
            validate_non_negative_index("alpha", "(J - 1)", (J - 1));
            Eigen::Matrix<double, Eigen::Dynamic, 1> alpha((J - 1));
            stan::math::initialize(alpha, DUMMY_VAR__);
            stan::math::fill(alpha, DUMMY_VAR__);
            current_statement_begin__ = 52;
            validate_non_negative_index("log_lik", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> log_lik(N);
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 54;
            if (as_bool(logical_eq(link_num, 1))) {
                current_statement_begin__ = 54;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 54;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                logit((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi")))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 55;
            if (as_bool(logical_eq(link_num, 2))) {
                current_statement_begin__ = 55;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 55;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                inv_Phi((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi")))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 56;
            if (as_bool(logical_eq(link_num, 3))) {
                current_statement_begin__ = 56;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 56;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                -(stan::math::log(-(stan::math::log((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi"))))))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 57;
            if (as_bool(logical_eq(link_num, 4))) {
                current_statement_begin__ = 57;
                for (int i = 2; i <= J; ++i) {
                    current_statement_begin__ = 57;
                    stan::model::assign(alpha, 
                                stan::model::cons_list(stan::model::index_uni((i - 1)), stan::model::nil_index_list()), 
                                stan::math::log(-(log1m((1 - sum(stan::model::rvalue(pi, stan::model::cons_list(stan::model::index_min_max(i, J), stan::model::nil_index_list()), "pi")))))), 
                                "assigning variable alpha");
                }
            }
            current_statement_begin__ = 59;
            stan::math::assign(log_lik, loglik(alpha, beta, delta, X, j, link_num, pstream__));
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t alpha_j_1_max__ = (J - 1);
                for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                    vars__.push_back(alpha(j_1__));
                }
                size_t log_lik_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                    vars__.push_back(log_lik(j_1__));
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    static std::string model_name() {
        return "model_multipe_dls_cpm";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t beta_j_1_max__ = p;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t pi_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t alpha_j_1_max__ = (J - 1);
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "alpha" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t log_lik_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t beta_j_1_max__ = p;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t pi_j_1_max__ = (J - 1);
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t alpha_j_1_max__ = (J - 1);
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "alpha" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t log_lik_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_multipe_dls_cpm_namespace::model_multipe_dls_cpm stan_model;
#endif