# Conceitos sobre UUID

O UUID é um identificador universal único atribuído ao beacon, cada região do beacon significa um elemento do próprio beacon. Abaixo descreveremos sobre o uso e suas validações.

**Validação UUID (REGEX)**
```javascript
/^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$/
```

- [RFC-4122](https://www.ietf.org/rfc/rfc4122.txt)
- Comando Linux para criação: [uuidgen](http://linuxcommand.org/man_pages/uuidgen1.html)
