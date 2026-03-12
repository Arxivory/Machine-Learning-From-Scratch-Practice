# ML/DL From Scratch in C++: A Mathematical-Oriented Approach

This repository is a project-based ML/DL math practice of mine containing a comprehensive suite of Machine Learning and Deep Learning algorithms implemented from first principles using C++. The project focuses on deriving the underlying mathematics (linear algebra, multivariable calculus, and optimization) and translating those derivations into efficient, low-level code.

## Project Goals
* **Mathematical Derivation:** Bridging the gap between abstract formulas and executable code.
* **Low-Level C++ Engineering:** Implementing high-performance infrastructure focusing on memory layout (row-major storage) and cache-friendly operations without high-level libraries (e.g., Eigen, OpenCV).
* **Numerical Stability:** Developing robust solvers for linear systems and handling floating-point edge cases in deep learning (e.g., Log-Sum-Exp trick).

## Core Infrastructure: Linear Algebra Library
The foundation of this project is a custom-built linear algebra library designed for performance and clarity.
* **Vector Class:** Supports $l_1$ and $l_2$ norms, inner products, and element-wise arithmetic.
* **Matrix Class:** High-performance matrix multiplication ($O(n^3)$ baseline), transpose operations, and identity matrix generation.
* **Linear Solvers:** Implementations of Gaussian Elimination and LU decomposition for solving systems like $Ax = b$ without explicit matrix inversion.

## Implemented Modules

### 1. Supervised Learning: Regression
* **Linear Regression:** Analytical solutions via Normal Equations ($w^* = (X^\top X)^{-1}X^\top y$) and Batch Gradient Descent.
* **Ridge Regression:** Implementation of $l_2$ regularization to combat overfitting and improve numerical stability in singular matrices.

### 2. Supervised Learning: Classification
* **Logistic Regression:** Binary classification using the Sigmoid activation and Maximum Likelihood Estimation (MLE) via Cross-Entropy loss.
* **Softmax Regression:** Multiclass classification using the Log-Sum-Exp trick for numerical overflow prevention.
* **Support Vector Machines (SVM):** Geometric margin maximization using the Hinge loss formulation.

### 3. Neural Networks & Deep Learning
* **Feedforward Networks:** Modular layer architecture (Dense, Activation) with full backpropagation derivation.
* **Activation Library:** Implementations for Sigmoid, Tanh, ReLU, Leaky ReLU, and ELU, including their local derivatives.
* **Convolutional Neural Networks (CNNs):** Mathematical foundations of convolution operations and backpropagation through convolutional kernels.
* **Optimizers:** Standard SGD, Momentum, and Adam optimization variants.

### 4. Unsupervised Learning & Dimensionality Reduction
* **K-Means Clustering:** Iterative centroid optimization based on Within-Cluster Sum of Squares (WCSS).
* **Principal Component Analysis (PCA):** Variance maximization via Eigendecomposition and visualization of components.

## Tech Stack
* **Environment:** Visual Studio 2022 (MSVC)
* **Language:** C++17/20
* **Paradigm:** Object-Oriented with a focus on "C-style" manual memory management for critical sections.
* **Build System:** `.sln` (Visual Studio Solution)

## Getting Started
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Arxivory/Machine-Learning-From-Scratch-Practice.git
    ```
2.  Open the `ML_Project.sln` file in **Visual Studio 2022**.
3.  Ensure your compiler is set to C++17 or higher.
4.  Run the code.

## References & Resources
* *Machine Learning & Deep Learning From Scratch in C++: A Mathematical-Oriented Programming Guide* (My created Study Guide).
* Bishop, C. M. (2006). *Pattern Recognition and Machine Learning*. Springer.
* Goodfellow, I., Bengio, Y., & Courville, A. (2016). *Deep Learning*. MIT Press.