package string

import (
	"strings"
	"runtime"
	"testing"
)

const msgIndex = "%s (parte: %s) - indices: esperado (%d): <> econtrado (%d)."

func TestIndex(t *testing.T) {
	testes := []struct {
		texto string
		parte string
		esperado int
	}{
		{"Código é isso", "Código", 0},
		{"", "", 0},
		{"Junior", "r", 5},
	}

	for _, teste := range testes {
		t.Logf("Massa: %v", teste)
		atual := strings.Index(teste.texto, teste.parte)

		if atual != teste.esperado {
			t.Errorf(msgIndex, teste.texto, teste.parte, teste.esperado, atual)
		}
	}
}

func TestDependente(t *testing.T) {
	if runtime.GOARCH == "amd64" {
		t.Skip("Não funciona em arquitetura amd64")
	}

	t.Fail()
}