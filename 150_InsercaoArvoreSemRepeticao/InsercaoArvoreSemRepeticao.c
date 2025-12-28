#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int chave;
    struct Node * pai;
    struct Node * direita;
    struct Node * esquerda;
} Node;

typedef struct Tree {
    struct Node *raiz;
} Tree;

Node * newNode(int chave) {
  Node *no = (Node *) malloc(sizeof(Node));

  no->chave = chave;
  no->pai = NULL;
  no->esquerda = NULL;
  no->direita = NULL;

  return no;
}

Tree * newTree() {
  Tree *t = (Tree *) malloc(sizeof(Tree));

  t->raiz = NULL;
  
  return t;
}

Node * raiz(Tree *t) {
  return t->raiz;
}

int arvoreVazia(Tree *t) {
  return raiz(t) == NULL;
}

void preOrder(Node *r) {
  printf("%d\n", r->chave);
  preOrder(r->esquerda);
  preOrder(r->direita);
}

void inOrder(Node *r) {
  inOrder(r->esquerda);
  printf("%d\n", r->chave);
  inOrder(r->direita);
}

void postOrder(Node *r) {
  postOrder(r->esquerda);
  postOrder(r->direita);
  printf("%d\n", r->chave);
}

Node * buscar(Tree *t, int chave) {
  Node *no = raiz(t);

  while(no != NULL && no->chave != chave) {
    if(no->chave < chave) {
      no = no->direita;
    } else {
      no = no->esquerda;
    }
  }
  return no;
}

void inserir(Tree *t, Node *novo) {
  Node *pai = NULL, *filho = raiz(t);

  while(filho != NULL) {
    pai = filho;
    if (filho->chave < novo->chave) {
      filho = filho->direita;
    } else {
      filho = filho->esquerda;
    }
  }

  if(pai != NULL) { // incluindo nao RAIZ
    novo->pai = pai;
    if(pai->chave < novo->chave) {
      pai->direita = novo;
    } else {
      pai->esquerda = novo;
    }
  } else {// incluindo RAIZ
    t->raiz = novo;
  }

}

Node * sucessor(Node *r) {
  Node *pai = NULL;
  r = r->direita;
  while(r != NULL) {
    pai = r;
    r = r->esquerda;
  }
  return pai;
}

Node * removerSucessor(Node *r) {
  Node *pai = r->pai;
  if(pai->esquerda == r) {
    pai->esquerda = r->direita;
  } else {
    pai->direita = r->direita;
  }
  if(r->direita != NULL) {
    r->direita->pai = pai;
  }
  r->pai = NULL;
  r->direita = NULL;
  return r;
}

Node * remover(Tree *t, int chave) {
  Node *pai = NULL, *filho = raiz(t), *subs;

  while(filho != NULL && filho->chave != chave) {
    pai = filho;
    if(filho->chave < chave) {
      filho = filho->direita;
    } else {
      filho = filho->esquerda;
    }
  }

  if (filho == NULL ) return NULL;

  if(filho->esquerda == NULL && filho->direita == NULL) {

    // eh folha
    if(pai != NULL) {
      if(pai->esquerda == filho) {
        pai->esquerda = NULL;
      } else {
        pai->direita = NULL;
      }
    } else {
      t->raiz = NULL;
    }

  } else if(filho->esquerda != NULL && filho->direita != NULL) {
    // pai de dois filhos
    subs = removerSucessor(sucessor(filho));

    subs->pai = pai;
    subs->esquerda = filho->esquerda;
    subs->direita = filho->direita;

    if(pai != NULL) {
      if(pai->esquerda == filho) {
        pai->esquerda = subs;
      } else {
        pai->direita = subs;
      }
    } else {
      t->raiz = subs;
    }

    if(filho->esquerda != NULL) {
      filho->esquerda->pai = subs;
    }

    if(filho->direita != NULL) {
      filho->direita->pai = subs;
    }

  } else {
    // pai de filho unico 
    if(pai != NULL) {
      // nao eh raiz
      if(pai->esquerda == filho) {
        if(filho->esquerda != NULL) {
          pai->esquerda = filho->esquerda;
          filho->esquerda->pai = pai;
        } else {
          pai->esquerda = filho->direita;
          filho->direita->pai = pai;
        }
      } else {
        if(filho->esquerda != NULL) {
          pai->direita = filho->esquerda;
          filho->esquerda->pai = pai;
        } else {
          pai->direita = filho->direita;
          filho->direita->pai = pai;
        }
      }

    } else  {
      // eh raiz
      if(filho->esquerda != NULL) {
        t->raiz = filho->esquerda;
        filho->esquerda->pai = NULL;
      } else {
        t->raiz = filho->direita;
        filho->direita->pai = NULL;
      }
    }
  }
  filho->pai = NULL;
  filho->esquerda = NULL;
  filho->direita = NULL;
  return filho;
}

int main() {
  int n, v;
  scanf("%d", &n);
  Tree *tree = newTree();
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    if (buscar(tree, v) != NULL) {
      printf("Chave %d ja existe na arvore!\n");
      continue;
    }
    inserir(tree, newNode(v));
  }
  
  return 0;
}